/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:47:57 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/10 14:18:33 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_u(va_list *list, t_struct *strct)
{
	unsigned int nbr;

	nbr = va_arg(*list, unsigned int);
	ft_putunsigned(nbr, strct);
}

/*
void    ft_treat_unsignedint()
{

}
*/