/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:07:21 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/11 13:46:18 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *strct)
{
	write(1, &c, 1);
	strct->res++;
}

void	ft_putstrprec(char *str, int size, t_struct *strct)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
	{
		ft_putchar(str[i], strct);
		i++;
	}
}

void	ft_putwidth(t_struct *strct, int width, int size, int iszero)
{	
	while (width - size > 0)
	{	
		if (iszero)
			ft_putchar('0', strct);
		else
			ft_putchar(' ', strct);
		width -= 1;
	}
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

long long int	number_size(long long nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
	{
		size++;
		if (nb < 0)
			nb = nb * -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
