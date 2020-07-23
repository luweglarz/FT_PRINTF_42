/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:44:40 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 12:40:58 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	conv_c(va_list *list, t_struct *strct)
{
	char c;

	c = va_arg(*list, int);
	print_char(c, strct);
}


void    print_char(char c, t_struct *strct)
{
	if (strct->minus == 0)
		ft_putwidth(strct, strct->width, 1);
	ft_putchar(c, strct);
	if(strct-> minus == 1)
		ft_putwidth(strct, strct->width,  1);;
}
