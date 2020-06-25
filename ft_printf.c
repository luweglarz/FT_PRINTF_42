/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/25 16:44:01 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_tab   g_tab[9] = {
    {'%', &conv_percent}, {'c', &conv_c }, {'s', &conv_s},
    {'p', &conv_p}, {'d', &conv_id}, {'i', &conv_id},
    {'u', &conv_u}, {'x', &conv_x}, {'X', &conv_X}
};

void    ft_parse(const char *str, t_struct *strct, va_list *args)
{
    int tempindex;
    int  i;

    i =0 ;
    strct->index = 0;
     while (str[strct->index])
    {
            
        if (str[strct->index] == '%' && str[strct->index + 1] != '%')
        {     
            tempindex = 0;
            strct->index++;
            while (tempindex <= 9 && check_convert(str[strct->index]) != g_tab[tempindex].name)
                tempindex++;
            g_tab[tempindex].TabFunc(args, strct);
        }
        else
            ft_putchar(str[strct->index], strct);
        strct->index++;
    }    
}

int        ft_printf(const char *format, ...)
{
    va_list args;
    t_struct strct;
    strct.res = 0;
    strct.index = 0;
    va_start(args, format);
    ft_parse(format, &strct, &args);
    va_end(args);
    return (strct.res);
}

#include <stdio.h>

int main()
{
    int hint;
    int res1;
    int res2;
    char *test;
    int  *testint;
    test = "test";
    hint = 42;
    testint = &hint;
    res1 = ft_printf("%c %s, %i %d %u %x %X %x %X %% %s %u %p\n", 'c', "test", 100, 150, 443242, 3341, 7888, -4311, -513212, "test", -53532,  testint);
    res2 = printf("%c %s, %i %d %u %x %X %x %X %% %s %u %p\n", 'c', "test", 100, 150, 443242, 3341, 7888, -4311, -513212, "test", -53532, testint);
    printf("%d\n", res1);
    printf("%d", res2);
}
