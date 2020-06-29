/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:09:36 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/29 15:36:04 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(va_list *list, t_struct *strct)
{
	char *str;

	str = va_arg(*list, char *);
	ft_putstr(str, strct);
}

void	conv_c(va_list *list, t_struct *strct)
{
	char c;

	c = va_arg(*list, int);
	ft_putchar(c, strct);
}

void	conv_p(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned long);
	ft_putptr(nbr, strct);
}

void	conv_id(va_list *list, t_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr(nbr, strct);
}
