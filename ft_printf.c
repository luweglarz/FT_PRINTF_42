/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/09 16:48:45 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

c_tab		g_tab[9] = {
	{'%', &conv_percent}, {'c', &conv_c }, {'s', &conv_s},
	{'p', &conv_p}, {'d', &conv_id}, {'i', &conv_id},
	{'u', &conv_u}, {'x', &conv_x}, {'X', &conv_capsx}
};

void		struct_init(t_struct *strct)
{
	strct->res = 0;
	strct->index = 0;
}	

void		flags_init(f_flags *strct)
{
	strct->pres = 0;
	strct->width = 0;
	strct->zero = 0;
	strct->star = 0;
	strct->minus = 0;
	strct->dot = 0;
}

int			is_flag(int c)
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

void		ft_parse_flags(const char *str, t_struct *strct, va_list *args, f_flags *flags)
{
		while (str[strct->index])
		{
		if (!ft_isdigit(str[strct->index]) && !is_flag(str[strct->index]))
			break ;
		if (str[strct->index] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[strct->index] == '.')
			conv_flag_dot(str, args, flags, strct);
		if (str[strct->index] == '-')
			conv_flag_minus(flags);
		if (str[strct->index] == '*')
			conv_flag_star(args, flags);
		if (ft_isdigit(str[strct->index]))
			conv_flag_digit(str[strct->index], flags);
		if (ft_isconv(str[strct->index]))
			break ;
		strct->index++;
		}
}

void		ft_parse(const char *str, t_struct *strct, va_list *args, f_flags *flags)
{
	int tempindex;
	
	while (str[strct->index])
	{
		flags_init(flags);
		if (str[strct->index] == '%')
		{
			tempindex = 0;
			strct->index++;
			//if (is_flag(str[strct->index]) || ft_isdigit(str[strct->index]))
			ft_parse_flags(str, strct, args, flags);
			while (tempindex <= 9 && str[strct->index] != g_tab[tempindex].name)
				tempindex++;
			g_tab[tempindex].tabcfunc(args, strct, flags);	
		}
		else
			ft_putchar(str[strct->index], strct, flags);
		strct->index++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	strct;
	f_flags     flags;
	struct_init(&strct);
	va_start(args, format);
	ft_parse(format, &strct, &args, &flags);
	va_end(args);
	return (strct.res);
}
