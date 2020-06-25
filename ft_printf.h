/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/25 16:35:33 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#   define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct   s_struct
{  
   int     index;
   int     res;
}              t_struct;

typedef struct    s_tab
{
   char     name;
   void     (*TabFunc)(va_list *, t_struct *);

}                 t_tab;


int		ft_printf(const char *str, ...);
void	conv_s(va_list *list, t_struct *strct);
void	conv_id(va_list *list, t_struct *strct);
void    conv_c(va_list *list, t_struct *strct);
void    conv_u(va_list *list, t_struct *strct);
void    conv_x(va_list *list, t_struct *strct);
void	  conv_X(va_list *list, t_struct *strct);
void    conv_p(va_list *list, t_struct *strct);
void    conv_percent(va_list *list, t_struct *strct);
char    check_convert(char c);
//void    conv(const char c, va_list args);
void    ft_putchar(char c, t_struct *strct);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int nb, t_struct *strct);
void	ft_puthexax(unsigned nbr, t_struct *strct);
void	ft_puthexaX(unsigned int nbr, t_struct *strct);
void	ft_putptr(int nbr, t_struct *strct);
void	ft_putstr(char *str, t_struct *strct);
void	ft_putunsigned(unsigned int nbr, t_struct *strct);

#endif
