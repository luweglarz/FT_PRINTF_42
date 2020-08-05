/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:50 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/05 22:05:40 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_flag_dot(char *str, va_list *args, t_struct *strct)
{
	strct->index++;
	strct->dot = 1;
	if (str[strct->index] == '*')
	{
		strct->prec = va_arg(*args, int);
		strct->index++;
	}
	while (ft_isdigit(str[strct->index]))
	{
		strct->prec = (strct->prec * 10) + (str[strct->index] - '0');
		strct->index++;
	}
}

void	conv_flag_minus(t_struct *strct)
{
	strct->minus = 1;
	strct->zero = 0;
}

void	conv_flag_star(va_list *args, t_struct *strct)
{
	strct->width = va_arg(*args, int);
	if (strct->width < 0 && strct->dot == 0)
	{
		strct->minus = 1;
		strct->width *= -1;
		strct->zero = 0;
	}
	strct->star = 1;
}

void	conv_flag_digit(char c, t_struct *strct)
{
	strct->width = (strct->width * 10) + (c - '0');
}
