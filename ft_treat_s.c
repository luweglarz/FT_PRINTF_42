/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:43:34 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/07 15:03:40 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	conv_s(va_list *list, t_struct *strct, f_flags *flags)
{
	char *str;

	str = va_arg(*list, char *);
	treat_string(str, strct, flags);
}

void    treat_string(char *str, t_struct *strct, f_flags *flags)
{
    if (flags->dot > 0)
        ft_putstrprec(str, strct, flags);
	else
		ft_putstr(str, strct);
}
