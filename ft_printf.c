/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/17 16:14:00 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}


void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
}


char    check_convert(const char c)
{
    int i;
    char convert[8] = "cspdiuxX";

    i = 0;
    while (convert[i])
    {
        if (c == convert[i])
            return (convert[i]);
        i++;
    }
    return (0);
}
/*
void    conv(const char c, va_list args)
{
    if (check_convert(c) == 'c')
        fl_c();
    else if (check_convert(c) == 's')
        fl_s();
    else if (check_convert(c) == 'p')
        fl_p();
    else if (check_convert(c) == 'd')
        fl_d();
    else if (check_convert(c) == 'i')
        fl_i();
    else if (check_convert(c) == 'u')
        fl_u();
    else if (check_convert(c) == 'x')
        fl_x();
    else    if (check_convert(c) == 'X')
        fl_X();
}
*/

int		ft_printf(const char *str, ...)
{
    int     res;
    va_list args;

    va_start(args, str);
    res = 0;
    while (*str)
    {
        if (*str == '%')
        {  
            str++;
            if (check_convert(*str) == 'c' || check_convert(*str) == 'C')
                ft_putchar(va_arg(args, int));
            else if (check_convert(*str) == 'd' || check_convert(*str) == 'i')
                ft_putnbr(va_arg(args, int));
            else if (check_convert(*str) == 'p')
                ft_putaddress(va_arg(args, int));
        }
        else
        {
            ft_putchar(*str);
            res++;
        }
    str++;
    }
    va_end(args);
    return (res);
}

int main()
{
    char test;
    test = 'd';
    ft_printf("%c", test);

}