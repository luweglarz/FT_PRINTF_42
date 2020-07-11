/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:46:13 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/10 14:40:20 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_p(va_list *list, t_struct *strct)
{
	unsigned long long nbr;

	nbr = va_arg(*list, unsigned long long);
	print_pointer(nbr, strct);
}


void    print_pointer(unsigned long long nbr, t_struct *strct)
{
		ft_putstr("0x", strct);
		ft_puthexax(nbr, strct);
}
