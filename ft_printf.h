/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/23 15:07:09 by lweglarz         ###   ########.fr       */
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

typedef struct   t_struct
{  
   int     index;
   int     res;

}           s_struct;

int		ft_printf(const char *str, ...);
void	conv_s(va_list *list, s_struct *strct);
void	conv_id(va_list *list, s_struct *strct);
void    conv_c(va_list *list, s_struct *strct);
void    conv_u(va_list *list, s_struct *strct);
void    conv_x(va_list *list, s_struct *strct);
void	  conv_X(va_list *list, s_struct *strct);
void    conv_p(va_list *list, s_struct *strct);
int     check_convert(const char c);
//void    conv(const char c, va_list args);
void    ft_putchar(char c, s_struct *strct);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int nb, s_struct *strct);
void	ft_puthexax(int nbr, s_struct *strct);
void	ft_puthexaX(int nbr, s_struct *strct);
void	ft_putptr(int nbr, s_struct *strct);
void	ft_putstr(char *str, s_struct *strct);
void	ft_putunsigned(unsigned int nbr, s_struct *strct);

#endif
