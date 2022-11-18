/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:07:21 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/03 11:52:36 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_strct(char c, t_struct *strct)
{
	write(1, &c, 1);
	strct->res++;
}

void	ft_putstrprec(char *str, int size, t_struct *strct)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
	{
		ft_putchar_strct(str[i], strct);
		i++;
	}
}

void	ft_putwidth(int width, int size, int fill, t_struct *strct)
{
	while (width - size > 0)
	{
		if (fill == 1)
			ft_putchar_strct('0', strct);
		else
			ft_putchar_strct(' ', strct);
		width -= 1;
	}
}
