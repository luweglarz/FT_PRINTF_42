/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:49:40 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/29 13:31:51 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_per(va_list *list, t_struct *strct)
{
	(void)list;
	if (strct->minus == 0)
		ft_putwidth(strct->width, 1, strct->zero, strct);
	ft_putchar_strct('%', strct);
	if (strct->minus == 1)
		ft_putwidth(strct->width, 1, strct->zero, strct);
}
