/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:43:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/08 15:13:34 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	conv_s(va_list *list, t_struct *strct, f_flags *flags)
{
	char *str;
	str = va_arg(*list, char *);
	print_string(str, strct, flags);
}

void    print_string(char *str, t_struct *strct, f_flags *flags)
{
	if (!str)
		str = (NULL);
	if (flags->minus == 1)
	{
		ft_putstr(str, strct);
		ft_putwidth(flags, strct, ft_strlen(str));
	}
    else if (flags->dot > 0)
        ft_putstrprec(str, strct, flags->dot, flags);
	else
		ft_putstrprec(str, strct, ft_strlen(str), flags);
}
