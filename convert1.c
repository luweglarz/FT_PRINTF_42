/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:09:36 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/01 12:14:36 by lweglarz         ###   ########.fr       */
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
	unsigned long long nbr;

	nbr = va_arg(*list, unsigned long long);
	ft_putstr("0x", strct);
	ft_puthexax(nbr, strct);
}

void	conv_id(va_list *list, t_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr(nbr, strct);
}
