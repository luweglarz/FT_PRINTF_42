/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:50 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/09 16:48:16 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void    conv_flag_dot(const char *str, va_list *args, f_flags *flags, t_struct *strct)
{
    strct->index++;
    if (str[strct->index] == '*')
    {
        flags->dot = va_arg(*args, int);
        strct->index++; 
    }   
    while (ft_isdigit(str[strct->index]))
    {
        flags->dot = (flags->dot * 10) + (str[strct->index] - '0');
        strct->index++;
    }
}

void    conv_flag_minus(f_flags *flags)
{
    flags->minus = 1;
    flags->zero = 0;
}

void    conv_flag_star(va_list *args, f_flags *flags)
{
    flags->width = va_arg(*args, int);
    flags->star = 1;
}

void    conv_flag_digit(char c, f_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
}