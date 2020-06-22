/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:09:36 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/22 15:33:34 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(va_list *list)
{
    char *str;

    str = va_arg(*list, char *);
	write(1, str, ft_strlen(str));
}

void    conv_c(va_list *list)
{
    char c;

    c = va_arg(*list, int);
    write(1, &c, 1);
}

void    conv_p(va_list *list)
{
    int nbr;

    nbr = va_arg(*list, int);
    ft_putptr(nbr);

}

void	conv_id(va_list *list)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr(nbr);
}

void    conv_u(va_list *list)
{
    unsigned int nbr;

    nbr = va_arg(*list, unsigned int);
    ft_putunsigned(nbr);
}

void    conv_x(va_list *list)
{
    int nbr;

    nbr = va_arg(*list, int);
    ft_puthexax(nbr);
}

void    conv_X(va_list *list)
{
    int nbr;

    nbr = va_arg(*list, int);
    ft_puthexaX(nbr);
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

