/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:43:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/11 14:17:02 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	conv_s(va_list *list, t_struct *strct)
{
	char *str;
	str = va_arg(*list, char *);
	if (!str)
		str = "(null)";
	ft_treat_string(str, strct);

}

void		ft_put_part_int(char *str, t_struct *strct)
{
	if (strct->dot >= 0)
	{
		ft_putwidth(strct, strct->dot, ft_strlen(str), 0);
		ft_putstrprec(str, strct->dot, strct);
	}
	else
	{
		ft_putstrprec(str, ft_strlen(str), strct);
	}
}

void			ft_treat_string(char *str, t_struct *strct)
{
	if (strct->dot >= 0 && (size_t)strct->dot > ft_strlen(str))
		strct->dot = ft_strlen(str);
	if (strct->minus == 1)
		ft_put_part_int(str, strct);
	if (strct->dot >= 0)
		ft_putwidth(strct, strct->width, strct->dot, 0);
	else
		ft_putwidth(strct, strct->width, ft_strlen(str), 0);
	if (strct->minus == 0)
		ft_put_part_int(str, strct);
}
