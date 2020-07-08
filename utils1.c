/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:07:21 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/08 15:05:25 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *strct, f_flags *flags)
{
	(void)flags;
	write(1, &c, 1);
	strct->res++;
}

void	ft_putstrprec(char *str, t_struct *strct, int size, f_flags *flags)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
	{	
		ft_putchar(str[i], strct, flags);
		i++;
	}	
}

void	ft_putwidth(f_flags *flags, t_struct *strct, int size)
{
	flags->width -= size;
	while (flags->width > 0)
	{
		ft_putchar(' ', strct, flags);
		flags->width -= 1;
	}
	while (flags->zero > 0)
	{
		ft_putchar('0', strct, flags);
		flags->zero -= 1;
	}
}

void	ft_putnbr(int nb, t_struct *strct, f_flags *flags)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', strct, flags);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, strct, flags);
		ft_putnbr(nbr % 10, strct, flags);
	}
	else
		ft_putchar(nbr + 48, strct, flags);
}
