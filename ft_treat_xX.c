/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:48:35 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/13 12:31:10 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	conv_x(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list,unsigned long long);
	ft_puthexax(nbr, strct);
}

void	conv_capsx(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	ft_puthexcapsx(nbr, strct);
}	

void	ft_printhexa()
{

	
}