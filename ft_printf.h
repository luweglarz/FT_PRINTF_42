/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/22 12:41:00 by lweglarz         ###   ########.fr       */
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
   //
   //   int     res;

//}        s_struct

int		ft_printf(const char *str, ...);
void	conv_s(va_list *list);
void	conv_id(va_list *list);
void    conv_c(va_list *list);
void    conv_x(va_list *list);
void	  conv_X(va_list *list);
void    conv_p(va_list *list);
int     check_convert(const char c);
//void    conv(const char c, va_list args);
void    ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int nb);
void	ft_puthexax(int nbr);
void	ft_puthexaX(int nbr);
void	ft_putptr(int nbr);
size_t	ft_strlen(const char *s);

#endif