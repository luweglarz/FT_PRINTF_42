/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:46:41 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/22 12:55:45 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
    void (*tabFunc[8]) (va_list *) = {conv_c, conv_s, conv_p, conv_id, conv_id, 0, conv_x, conv_X};
    int index;
    int i;
    int res;
    va_list args;

    va_start(args, str);
    res = 0;
    index = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {  
            i++;
            index = check_convert(str[i]);
            if (index != -1)
                (*tabFunc[index])(&args);
        }
        else
            ft_putchar(str[i]);
    i++;
    } 
    va_end(args);
    return (res);
}


#include <stdio.h>

int main()
{
    char *test;
    test = "test";
    ft_printf("%x %X %p \n",42, 44, test);
    printf("%x %X %p \n",42, 44, test);

}
