/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:48:35 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/30 15:30:02 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_x(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned long long);
	if (strct->prec < 0)
	{
		strct->prec = 1;
		strct->precisneg = 1;
	}
	ft_print_hexa(nbr, 1, strct);
}

void		conv_capsx(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	if (strct->prec < 0)
	{
		strct->prec = 1;
		strct->precisneg = 1;
	}
	ft_print_hexa(nbr, 0, strct);
}

void		ft_put_minus_hexa(char *str, t_struct *strct)
{
	if (strct->dot == 1 && strct->precisneg == 0)
	{
		ft_putwidth(strct->prec, ft_strlen(str), 1, strct);
		ft_putstrprec(str, strct->prec, strct);
	}
	else
		ft_putstrprec(str, ft_strlen(str), strct);
}

void		ft_print_hexa(long long nbr, int islower, t_struct *strct)
{
	char *str;

	str = ft_itoa_hexa(nbr);
	if (islower)
		ft_lowerstr(str);
	if (nbr == 0 && strct->prec == 0 && strct->dot == 1)
		*str = '\0';
	if ((size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_minus_hexa(str, strct);
	if (strct->dot == 1 && strct->precisneg == 0)
		ft_putwidth(strct->width, strct->prec, 0, strct);
	else
		ft_putwidth(strct->width, ft_strlen(str), strct->zero, strct);
	if (strct->minus == 0)
		ft_put_minus_hexa(str, strct);
	free(str);
}
