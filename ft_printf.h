/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/09 16:48:28 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_struct
{
	int		index;
	int		res;
}					t_struct;

typedef struct		s_flags
{
	int		pres;
	int		minus;
	int		width;
	int		zero;
	int	    star;
	int		dot;

}					f_flags;

typedef struct		conv_tab
{
	char	name;
	void	(*tabcfunc)(va_list *, t_struct *, f_flags *);
}					c_tab;

int					ft_printf(const char *str, ...);
void				conv_s(va_list *list, t_struct *strct, f_flags *flags);
void				conv_id(va_list *list, t_struct *strct, f_flags *flags);
void				conv_c(va_list *list, t_struct *strct, f_flags *flags);
void				conv_u(va_list *list, t_struct *strct, f_flags *flags);
void				conv_x(va_list *list, t_struct *strct, f_flags *flags);
void				conv_capsx(va_list *list, t_struct *strct, f_flags *flags);
void				conv_p(va_list *list, t_struct *strct, f_flags *flags);
void				conv_percent(va_list *list, t_struct *strct, f_flags *flags);
void    			conv_flag_dot(const char *str, va_list *args, f_flags *flags, t_struct *strct);
void				ft_putchar(char c, t_struct *strct, f_flags *flags);
size_t				ft_strlen(const char *s);
void		ft_putnbr(int nb, t_struct *strct, f_flags *flags);
void	ft_puthexax(unsigned long long nbr, t_struct *strct, f_flags *flags);
void	ft_puthexcapsx(unsigned int nbr, t_struct *strct, f_flags *flags);
void				ft_putptr(void *nbr, t_struct *strct, f_flags *flags);
void	ft_putstrprec(char *str, t_struct *strct, f_flags *flags);
void		ft_putunsigned(unsigned int nbr, t_struct *strct, f_flags *flags);
int					ft_isdigit(int c);
void    	print_string(char *str, t_struct *strct, f_flags *flags);
void	ft_putstr(char *str, t_struct *strct);
void    conv_flag_minus(f_flags *flags);
void    conv_flag_star(va_list *args, f_flags *flags);
void	ft_putwidth(f_flags *flags, t_struct *strct, int size);
void    print_char(char c, t_struct *strct, f_flags *flags);
void    	print_pointer(unsigned long long nbr, t_struct *strct, f_flags *flags);
long long	number_size(long long nb);
void    print_id(int nbr, t_struct *strct, f_flags *flags);
int		ft_isconv(int c);
void    conv_flag_digit(char c, f_flags *flags);
#endif
