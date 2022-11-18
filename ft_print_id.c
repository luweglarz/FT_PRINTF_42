/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:03 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/03 11:52:52 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_id(va_list *list, t_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	if (strct->prec < 0)
	{
		strct->prec = 1;
		strct->precisneg = 1;
	}
	ft_print_integer(nbr, strct);
}

void		ft_put_minus_integer(char *str, t_struct *strct, int hasneg)
{
	if (strct->neg == 1 && hasneg == 0)
		ft_putchar_strct('-', strct);
	if (strct->dot == 1 && strct->precisneg == 0)
	{
		ft_putwidth(strct->prec, ft_strlen(str), 1, strct);
		ft_putstrprec(str, strct->prec, strct);
	}
	else
	{
		ft_putstrprec(str, ft_strlen(str), strct);
	}
}

void		ft_print_integer(int nbr, t_struct *strct)
{
	char	*str;
	int		hasneg;

	hasneg = 0;
	str = ft_itoapos(nbr);
	ft_isneg(nbr, strct);
	if (nbr == 0 && strct->dot == 1 && strct->prec == 0)
		*str = '\0';
	if (strct->dot == 1 && (size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if ((strct->neg == 1 && strct->precisneg == 1 && strct->zero == 1) ||
		(strct->neg == 1 && strct->zero == 1 && strct->dot == 0))
	{
		hasneg = 1;
		ft_putchar_strct('-', strct);
	}
	if (strct->minus == 1)
		ft_put_minus_integer(str, strct, hasneg);
	if (strct->dot == 1 && strct->precisneg == 0)
		ft_putwidth(strct->width, strct->prec, 0, strct);
	else
		ft_putwidth(strct->width, ft_strlen(str), strct->zero, strct);
	if (strct->minus == 0)
		ft_put_minus_integer(str, strct, hasneg);
	free(str);
}
