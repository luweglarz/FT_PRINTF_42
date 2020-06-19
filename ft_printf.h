/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/19 16:54:50 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#   define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

//struct  flags
//{

//}

//struct   t_struct
//{
   // int     index;
   // int     i;

//}        s_struct

int		ft_printf(const char *str, ...);
void	conv_s(va_list *list);
void	conv_id(va_list *list);
void    conv_c(va_list *list);
int     check_convert(const char c);
//void    conv(const char c, va_list args);
void    ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int nb);


#endif