/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:03 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/10 14:14:50 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	conv_id(va_list *list, t_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	print_id(nbr, strct);
}


void    print_id(int nbr, t_struct *strct)
{
	ft_putnbr(nbr, strct);ft_putnbr(nbr, strct);
}