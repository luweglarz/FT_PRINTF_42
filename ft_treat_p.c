/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:46:13 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 12:54:31 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	conv_p(va_list *list, t_struct *strct)
{
	unsigned long long nbr;

	nbr = va_arg(*list, unsigned long long);
	print_pointer(nbr, strct);
}

void		ft_put_minuspointer(char *str, t_struct *strct)
{
	ft_putstrprec("0x", 2, strct);
	if (strct->dot == 1)
	{
		strct->zero = 1;
		ft_putwidth(strct , strct->prec, ft_strlen(str));
		ft_putstrprec(str, strct->prec, strct);
	}
	else
		ft_putstrprec(str, ft_strlen(str), strct);
}

void	ft_lowerstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int   print_pointer(unsigned long long nbr, t_struct *strct)
{
	char *str;

	str = ft_itoa_hexa(nbr);
	ft_lowerstr(str);
	if ((size_t)strct->prec < ft_strlen(str))
		strct->prec = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_minuspointer(str, strct);
	ft_putwidth(strct, strct->width, ft_strlen(str) + 2);
	if (strct->minus == 0)
		ft_put_minuspointer(str, strct);
	free (str);
	return (1);
}
