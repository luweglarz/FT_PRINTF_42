/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:08:32 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/17 14:08:34 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int	size;
	int	count;

	count = 0;
	if (!s1)
		return (NULL);
	while (ft_is_set(s1[count], set) == 1 && s1[count] != '\0')
		count++;
	size = ft_strlen(s1);
	while (ft_is_set(s1[size - 1], set) == 1 && size > 0)
		size--;
	if (size == 0)
		size = 0;
	else
		size = size - count;
	return (ft_substr(s1, count, size));
}
