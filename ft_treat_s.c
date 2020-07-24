/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:43:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/24 15:33:47 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		conv_s(va_list *list, t_struct *strct)
{
	char *str;

	str = va_arg(*list, char *);
	if (!str)
		str = "(null)";
	ft_print_string(str, strct);
}

void		ft_put_minus_string(char *str, t_struct *strct)
{
	if (strct->dot == 1)
		ft_putstrprec(str, strct->prec, strct);
	else
		ft_putstrprec(str, ft_strlen(str), strct);
}

void		ft_print_string(char *str, t_struct *strct)
{
	if (strct->dot == 1 && (size_t)strct->prec > ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_minus_string(str, strct);
	if (strct->dot == 1)
		ft_putwidth(strct->width, strct->prec, strct);
	else
		ft_putwidth(strct->width, ft_strlen(str), strct);
	if (strct->minus == 0)
		ft_put_minus_string(str, strct);
}
