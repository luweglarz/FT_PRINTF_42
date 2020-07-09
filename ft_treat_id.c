/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:03 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/09 11:41:24 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	conv_id(va_list *list, t_struct *strct, f_flags *flags)
{
	int	nbr;

	nbr = va_arg(*list, int);
	print_id(nbr, strct, flags);
}


void    print_id(int nbr, t_struct *strct, f_flags *flags)
{

	ft_putnbr(nbr, strct, flags);ft_putnbr(nbr, strct, flags);
}