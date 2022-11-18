/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:02:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/03 11:54:18 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
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

void			ft_isneg(int nbr, t_struct *strct)
{
	if (nbr < 0)
	{
		strct->neg = 1;
		strct->width--;
	}
}
