/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:03 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/29 16:38:33 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		conv_id(va_list *list, t_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	if (strct->prec < 0)
		strct->prec = 1;
	ft_print_integer(nbr, strct);
}

void		ft_put_minus_integer(char *str, t_struct *strct, int neg)
{
	if (strct->dot == 1)
	{
		if (neg == 1)
			ft_putchar('-', strct);
		ft_putwidth(strct->prec, ft_strlen(str), 1, strct);
		ft_putstrprec(str, strct->prec, strct);
	}
	else
	{
		if (neg == 1 && strct->zero == 0)
			ft_putchar('-', strct);
		ft_putstrprec(str, ft_strlen(str), strct);
	}
}

void		ft_print_integer(int nbr, t_struct *strct)
{
	char	*str;
	int		neg;

	str = ft_itoapos(nbr);
	neg = ft_isneg(nbr, strct);
	if (nbr == 0 && strct->dot == 1 && strct->prec == 0)
		*str = '\0';
	if ((size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (neg == 1 && strct->dot == 0 && strct->zero == 1)
		ft_putchar('-', strct);
	if (strct->minus == 1)
		ft_put_minus_integer(str, strct, neg);
	if (strct->dot == 1 && strct->prec > 1)
		ft_putwidth(strct->width, strct->prec, 0, strct);
	else
		ft_putwidth(strct->width, ft_strlen(str), strct->zero, strct);
	if (strct->minus == 0)
		ft_put_minus_integer(str, strct, neg);
	free(str);
}
