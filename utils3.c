/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:43:59 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 11:53:50 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_init(t_struct *strct)
{
	strct->res = 0;
	strct->index = 0;
}	

void		flags_init(t_struct *strct)
{
	strct->prec = 0;
	strct->width = 0;
	strct->zero = 0;
	strct->star = 0;
	strct->minus = 0;
	strct->dot = 0;
}

int			ft_is_flag(int c)
{
	char 	*flags;
	int		i;

	i = 0;
	flags = "-0.*";
	while (flags[i])
	{
		if(c == flags[i])
			return (1);
		i++;
	}
	return (0);
}	

int		ft_isconv(int c)
{
	char	*conv;
	int		i;

	conv = "cspdiuxX";
	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}