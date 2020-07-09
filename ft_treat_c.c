/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:44:40 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/09 14:52:33 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	conv_c(va_list *list, t_struct *strct, f_flags *flags)
{
	char c;

	c = va_arg(*list, int);
	print_char(c, strct, flags);
}


void    print_char(char c, t_struct *strct, f_flags *flags)
{
	if (flags->minus == 1)
		ft_putchar(c, strct, flags);
	ft_putwidth(flags, strct, 1);
	if(flags-> minus == 0)
		ft_putchar(c, strct, flags);
}
