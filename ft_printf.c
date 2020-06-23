/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/23 15:14:50 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_parse(const char *str, va_list *args, s_struct *strct, void (**tabFunc)(va_list *, s_struct *))
{
    int tempindex;

    tempindex = 0;
    while (str[strct->index])
    {
        if (str[strct->index] == '%' && str[strct->index + 1] != '%')
        {  
            strct->index++;
            tempindex = check_convert(str[strct->index]);
            if (tempindex != -1)
                (tabFunc)[tempindex](args, strct);
        }
        else
            ft_putchar(str[strct->index], strct);
    strct->index++;
    } 

}

int		ft_printf(const char *format, ...)
{
    va_list args;
    s_struct strct;
    void (*tabFunc[8]) (va_list *, s_struct *) = {conv_c, conv_s, conv_p, conv_id, conv_id, conv_u, conv_x, conv_X};

    strct.res = 0;
    va_start(args, format);
    ft_parse(format, &args, &strct, (tabFunc));
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
    res1 = ft_printf("%c %s, %i %d %u %x %X %% \n", 'c', "test", 100, 150, 443242, 3341, 7888);
    res2 = printf("%c %s, %i %d %u %x %X %% \n", 'c', "test",  100, 150, 443242, 3341, 7888);
    printf("%d\n", res1);
    printf("%d", res2);
}
