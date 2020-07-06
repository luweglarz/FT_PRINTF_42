/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:50 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/06 16:20:24 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    conv_flag_dot(const char *str, va_list *args, f_flags *flags, t_struct *strct)
{
    if (str[strct->index + 1] == '*')
    {
        flags->dot = va_arg(*args, int);
        strct->index++; 
    }   
    else
    {

        while (is_digit(str[strct->index]))
        {
                

        }
    }
}