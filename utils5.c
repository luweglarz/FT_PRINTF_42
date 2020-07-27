/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 12:38:39 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/27 15:21:56 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoapos(int n)
{
	char				*str;
	unsigned int		size;
	long nbr;
	
	nbr = n;
	size = number_size(n);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		size--;
		nbr = nbr * -1;
	}
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
	char				*str;
	unsigned int		size;
	unsigned long nbr;
	
	nbr = n;
	size = number_size(n);
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

	size = number_size(n);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		size--;
		if (n % 16 < 10)
			str[size] = (n % 16) + 48;
		else
			str[size] = (n % 16) + 55;
		n = n / 16;
	}
	return (str);
}
