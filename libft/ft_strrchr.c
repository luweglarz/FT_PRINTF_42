/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:07:33 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/17 14:07:37 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	if (c == 0)
		return ((char *)s + size);
	while (size > 0)
	{
		size--;
		if (s[size] == (char)c)
			return ((char *)s + size);
	}
	return (0);
}
