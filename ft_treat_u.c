/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:57 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/27 15:20:02 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_u(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	ft_print_unsigned(nbr, strct);
}


void		ft_put_minus_unsigned(char *str, t_struct *strct)
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

void		ft_print_unsigned(unsigned int nbr, t_struct *strct)
{
	char *str;

	str = ft_uitoapos(nbr);
	if (nbr == 0 && strct->dot == 1 && strct->prec == 0)
		*str = '\0';
	if ((size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_minus_unsigned(str, strct);
	if (strct->dot == 1)
	{
		strct->zero = 0;
		ft_putwidth(strct->width, strct->prec, strct);
	}
	else
		ft_putwidth(strct->width, ft_strlen(str), strct);
	if (strct->minus == 0)
		ft_put_minus_unsigned(str, strct);
	free(str);
}

