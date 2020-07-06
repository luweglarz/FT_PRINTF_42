/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:34:16 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/06 16:11:26 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexax(unsigned long long nbr, t_struct *strct)
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

void	ft_putptr(void *nbr, t_struct *strct)
{
	ft_putstr("0x", strct);
	ft_puthexax((size_t)nbr, strct);
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}