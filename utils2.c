/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:34:16 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/29 15:06:41 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexax(unsigned nbr, t_struct *strct)
{
	char *hexa_base;

	hexa_base = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthexax(nbr / 16, strct);
	ft_putchar(hexa_base[(nbr % 16)], strct);
}

void	ft_puthexcapsx(unsigned int nbr, t_struct *strct)
{
	char *hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_puthexcapsx(nbr / 16, strct);
	ft_putchar(hexa_base[(nbr % 16)], strct);
}

void	ft_putptr(unsigned long nbr, t_struct *strct)
{
	ft_putstr("0x", strct);
	ft_puthexax(nbr, strct);
}

void	ft_putunsigned(unsigned int nbr, t_struct *strct)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, strct);
		ft_putnbr(nbr % 10, strct);
	}
	else
		ft_putchar(nbr + 48, strct);
}
