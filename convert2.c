/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:34:21 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/01 14:39:28 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_u(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	ft_putunsigned(nbr, strct);
}

void	conv_x(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	ft_puthexax(nbr, strct);
}

void	conv_capsx(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	ft_puthexcapsx(nbr, strct);
}	

void	conv_percent(va_list *list, t_struct *strct)
{
	(void)list;
	ft_putchar('%', strct);
}
