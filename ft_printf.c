/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/22 13:44:01 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// Initialisation de ma structure de tableau de fonction

t_tab		g_tab[9] = {
	{'%', &conv_per}, {'c', &conv_c }, {'s', &conv_s},
	{'p', &conv_p}, {'d', &conv_id}, {'i', &conv_id},
	{'u', &conv_u}, {'x', &conv_x}, {'X', &conv_capsx}
};

// Fonction de parsing des sub-specifiers

void		ft_parse_subspec(const char *str, t_struct *strct, va_list *args)
{
		while (str[strct->index])
		{
		if (!ft_isdigit(str[strct->index]) && !ft_is_flag(str[strct->index]))
			break;
		if (str[strct->index] == '0' && strct->width == 0 && strct->minus == 0)
			strct->zero = 1;
		if (str[strct->index] == '.')
			conv_flag_dot((char *)str, args, strct);
		if (str[strct->index] == '-')
			conv_flag_minus(strct);
		if (str[strct->index] == '*')
			conv_flag_star(args, strct);
		if (ft_isdigit(str[strct->index]))
			conv_flag_digit(str[strct->index], strct);
		if (ft_isconv(str[strct->index]))
			break;
		strct->index++;
		}
}

// Fonction de parsing des caracteres de conversion

void		ft_parse(const char *str, t_struct *strct, va_list *args)
{
	int tempindex;

	while (str[strct->index])
	{
		flags_init(strct);
		if (str[strct->index] == '%')
		{
			tempindex = 0;
			strct->index++;
			ft_parse_subspec(str, strct, args);
			while (tempindex <= 9 && str[strct->index] != g_tab[tempindex].conv)
				tempindex++;
			g_tab[tempindex].tabcfunc(args, strct);
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
