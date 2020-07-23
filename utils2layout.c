/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:34:16 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 14:03:25 by lweglarz         ###   ########.fr       */
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

void	ft_puthexcapsx(unsigned long long nbr, t_struct *strct)
{
	char *hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_puthexcapsx(nbr / 16, strct);
	ft_putchar(hexa_base[(nbr % 16)], strct);
}


void	ft_putunsigned(unsigned int nbr, t_struct *strct)
{
	if (nbr > 9)
	{
		ft_putunsigned(nbr / 10, strct);
		ft_putunsigned(nbr % 10, strct);
	}
	else
		ft_putchar(nbr + 48, strct);
}

void	ft_putstr(char *str, t_struct *strct)
{
	int size;

	size = ft_strlen(str);
	write(1, str, size);
	strct->res += size;
}
