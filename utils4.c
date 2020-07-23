/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:02:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 14:04:47 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
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

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long int	number_size(long long nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
	{
		size++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
