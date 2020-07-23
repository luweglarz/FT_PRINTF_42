/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:49:40 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 15:11:03 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_per(va_list *list, t_struct *strct)
{
	(void)list;
	if (strct->minus == 0)
		ft_putwidth(strct, strct->width, 1);
	ft_putchar('%', strct);
	if (strct->minus == 1)
		ft_putwidth(strct,strct->width, 1);
}
