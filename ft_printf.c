/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/01 15:43:56 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

c_tab		g_tab[9] = {
	{'%', &conv_percent}, {'c', &conv_c }, {'s', &conv_s},
	{'p', &conv_p}, {'d', &conv_id}, {'i', &conv_id},
	{'u', &conv_u}, {'x', &conv_x}, {'X', &conv_capsx}
};

//f_tab		h_tab[4] = {
	//{'*', &ft_star}, {'.', &ft_dot},
	//{'-', &ft_minus}, {'0', &ft_zero}
//};

void		struct_init(t_struct *strct)
{
	strct->res = 0;
	strct->index = 0;
}

void		ft_parse(const char *str, t_struct *strct, va_list *args)
{
	int tempindex;

	while (str[strct->index])
	{
		if (str[strct->index] == '%')
		{
			tempindex = 0;
			strct->index++;
			while (tempindex <= 9 && str[strct->index] != g_tab[tempindex].name)
				tempindex++;
			g_tab[tempindex].tabcfunc(args, strct);
			//while (tempindex <= 4 && str[strct->index] != h_tab[tempindex].name)
				//tempindex++;
			//h_tab[tempindex].tabffunc(str, args, strct);
		}
		else
			ft_putchar(str[strct->index], strct);
		strct->index++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	strct;

	struct_init(&strct);
	va_start(args, format);
	ft_parse(format, &strct, &args);
	va_end(args);
	return (strct.res);
}
