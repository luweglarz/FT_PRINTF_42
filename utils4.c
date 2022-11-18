/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 12:38:39 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/03 11:52:37 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoapos(int n)
{
	char				*str;
	int					size;
	long long			nbr;

	nbr = n;
	size = number_size(n, 10);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr != 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (str);
}

char		*ft_uitoapos(unsigned int n)
{
	char			*str;
	unsigned int	size;
	unsigned long	nbr;

	nbr = n;
	size = number_size(n, 10);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (str);
}

char		*ft_itoa_hexa(unsigned long long n)
{
	char				*str;
	unsigned int		size;

	size = 0;
	size = number_size(n, 16);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		if (n % 16 < 10)
			str[size] = (n % 16) + 48;
		else
			str[size] = (n % 16) + 55;
		n = n / 16;
		size--;
	}
	return (str);
}
