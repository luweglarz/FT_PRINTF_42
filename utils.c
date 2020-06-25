/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:07:21 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/25 15:02:19 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void    ft_putchar(char c, t_struct *strct)
{
    write(1, &c, 1);
	strct->res++;
}

void	ft_putstr(char *str, t_struct *strct)
{
	int size;
	size = ft_strlen(str);
	write(1, str, size);
	strct->res += size;
}

void	ft_putnbr(int nb, t_struct *strct)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', strct);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, strct);
		ft_putnbr(nbr % 10, strct);
	}
	else
		ft_putchar(nbr + 48, strct);
}

void	ft_puthexax(unsigned nbr, t_struct *strct)
{
    char *hexa_base;

	hexa_base = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthexax(nbr / 16, strct);
		ft_putchar(hexa_base[(nbr % 16)], strct);
}

void	ft_puthexaX(unsigned int nbr, t_struct *strct)
{
    char *hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_puthexaX(nbr / 16, strct);
	ft_putchar(hexa_base[(nbr % 16)], strct);
}

void	ft_putptr(int nbr, t_struct *strct)
{
	ft_putstr("0x", strct);
	ft_puthexax(nbr, strct);
}

void	ft_putunsigned(unsigned int nbr, t_struct *strct)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, strct);
		ft_putnbr(nbr % 10 ,strct);
	}
	else
		ft_putchar(nbr + 48, strct);
}