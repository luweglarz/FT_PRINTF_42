/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:50 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/08 15:11:07 by lweglarz         ###   ########.fr       */
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

void    conv_flag_minus(f_flags *flags, t_struct *strct)
{
    flags->minus = 1;
    flags->zero = 0;
    strct->index++;
}

void    conv_flag_star(va_list *args, f_flags *flags, t_struct *strct)
{
    flags->width = va_arg(*args, int);
    flags->star = 1;
    strct->index++;
}