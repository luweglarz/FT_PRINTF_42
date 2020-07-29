/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:02:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/29 11:35:23 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long		number_size(long long nb, int base)
{
	int	size;

	size = 0;
	if (nb == 0)
		size++;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		nb = nb / base;
		size++;
	}
	return (size);
}

int				ft_isneg(int nbr, t_struct *strct)
{
	int neg;

	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		strct->width--;
	}
	return (neg);
}
