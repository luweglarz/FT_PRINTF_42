/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:46:13 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/29 13:25:45 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_p(va_list *list, t_struct *strct)
{
	unsigned long long nbr;

	nbr = va_arg(*list, unsigned long long);
	if (strct->prec < 0)
		strct->prec = 1;
	ft_print_pointer(nbr, strct);
}

void		ft_put_minus_pointer(char *str, t_struct *strct)
{
	ft_putstrprec("0x", 2, strct);
	if (strct->dot == 1)
	{
		ft_putwidth(strct->prec, ft_strlen(str), 1, strct);
		ft_putstrprec(str, strct->prec, strct);
	}
	else
		ft_putstrprec(str, ft_strlen(str), strct);
}

void		ft_print_pointer(unsigned long long nbr, t_struct *strct)
{
	char *str;

	str = ft_itoa_hexa(nbr);
	ft_lowerstr(str);
	if (nbr == 0 && strct->prec == 0 && strct->dot == 1)
		*str = '\0';
	if ((size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_minus_pointer(str, strct);
	ft_putwidth(strct->width, ft_strlen(str) + 2, 0, strct);
	if (strct->minus == 0)
		ft_put_minus_pointer(str, strct);
	free(str);
}
