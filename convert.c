/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:09:36 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/23 15:06:42 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(va_list *list, s_struct *strct)
{
    char *str;

    str = va_arg(*list, char *);
	ft_putstr(str, strct);
}

void    conv_c(va_list *list, s_struct *strct)
{
    char c;

    c = va_arg(*list, int);
    ft_putchar(c, strct);
}

void    conv_p(va_list *list, s_struct *strct)
{
    unsigned int nbr;

    nbr = va_arg(*list, int);
    ft_putptr(nbr, strct);

}

void	conv_id(va_list *list, s_struct *strct)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr(nbr, strct);
}

void    conv_u(va_list *list, s_struct *strct)
{
    unsigned int nbr;

    nbr = va_arg(*list, unsigned int);
    ft_putunsigned(nbr, strct);
}

void    conv_x(va_list *list, s_struct *strct)
{
    int nbr;

    nbr = va_arg(*list, int);
    ft_puthexax(nbr, strct);
}

void    conv_X(va_list *list, s_struct *strct)
{
    int nbr;

    nbr = va_arg(*list, int);
    ft_puthexaX(nbr, strct);
}

int    check_convert(const char c)
{
    int i;
    char convert[8] = "cspdiuxX";

    i = 0;
    while (convert[i])
    {
        if (c == convert[i])
            return (i);
        i++;
    }
    return (-1);
}

