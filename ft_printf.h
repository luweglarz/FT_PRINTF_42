/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/29 13:23:25 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_struct
{
	int		index;
	int		res;

	int		prec;
	int		minus;
	int		width;
	int		zero;
	int		star;
	int		dot;
}				t_struct;

typedef struct	s_tab
{
	char	conv;
	void	(*tabcfunc)(va_list *, t_struct *);
}				t_tab;

int				ft_printf(const char *str, ...);

void			ft_parse_subsp(const char *str, t_struct *strct, va_list *args);
void			ft_parse(const char *str, t_struct *strct, va_list *args);

void			conv_s(va_list *list, t_struct *strct);
void			conv_id(va_list *list, t_struct *strct);
void			conv_c(va_list *list, t_struct *strct);
void			conv_u(va_list *list, t_struct *strct);
void			conv_x(va_list *list, t_struct *strct);
void			conv_capsx(va_list *list, t_struct *strct);
void			conv_p(va_list *list, t_struct *strct);
void			conv_per(va_list *list, t_struct *strct);

void			conv_flag_dot(char *str, va_list *args, t_struct *strct);
void			conv_flag_minus(t_struct *strct);
void			conv_flag_star(va_list *args, t_struct *strct);
void			conv_flag_digit(char c, t_struct *strct);

void			ft_putchar(char c, t_struct *strct);
void			ft_puthexax(unsigned long long nbr, t_struct *strct);
void			ft_puthexcapsx(unsigned long long nbr, t_struct *strct);
void			ft_putstrprec(char *str, int size, t_struct *strct);
void			ft_putunsigned(unsigned int nbr, t_struct *strct);
void			ft_putwidth(int width, int size, int fill, t_struct *strct);

void			ft_print_char(char c, t_struct *strct);
void			ft_put_minus_string(char *str, t_struct *strct);
void			ft_print_string(char *str, t_struct *strct);
void			ft_put_minus_pointer(char *str, t_struct *strct);
void			ft_print_pointer(unsigned long long nbr, t_struct *strct);
void			ft_put_minus_integer(char *str, t_struct *strct, int neg);
void			ft_print_integer(int nbr, t_struct *strct);
void			ft_put_minus_unsigned(char *str, t_struct *strct);
void			ft_print_unsigned(unsigned int nbr, t_struct *strct);
void			ft_put_minus_hexa(char *str, t_struct *strct);
void			ft_print_hexa(long long nbr, int islower, t_struct *strct);

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
long long		number_size(long long nb, int base);
int				ft_isconv(int c);
void			struct_init(t_struct *strct);
void			flags_init(t_struct *strct);
int				ft_is_flag(int c);
int				ft_tolower(int c);
void			ft_lowerstr(char *str);
char			*ft_itoa_hexa(unsigned long long n);
char			*ft_strdup(const char *s);
char			*ft_itoapos(int n);
char			*ft_uitoapos(unsigned int n);
int				ft_isneg(int nbr, t_struct *strct);

#endif
