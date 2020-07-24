/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:03 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/24 15:29:50 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_id(va_list *list, t_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_print_integer(nbr, strct);
}

void		ft_put_minus_integer(char *str, t_struct *strct)
{
	if (strct->dot == 1)
	{
		strct->zero = 1;
		ft_putwidth(strct->prec, ft_strlen(str), strct);
		ft_putstrprec(str, strct->prec, strct);
	}
	else
		ft_putstrprec(str, ft_strlen(str), strct);
}

void		ft_print_integer(int nbr, t_struct *strct)
{
	char *str;

	str = ft_itoa(nbr);
	if (nbr == 0 && strct->prec == 0 && strct->dot == 1)
		*str = '\0';
	if ((size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_minus_integer(str, strct);
	ft_putwidth(strct->width, ft_strlen(str), strct);
	if (strct->minus == 0)
		ft_put_minus_integer(str, strct);
	free(str);
}
