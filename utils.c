/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:07:21 by lweglarz          #+#    #+#             */
/*   Updated: 2020/06/19 16:38:10 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
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

void	ft_puthexa(int nbr)
{
    char *hexaDeciNum; 
    int	i;
	int tempnb;

	i = 0;
	hexaDeciNum = 0;
    while(nbr != 0) 
    {    
        tempnb = 0; 
          
        tempnb = nbr % 16; 
        if(tempnb < 10) 
        { 
            hexaDeciNum[i] = tempnb + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = tempnb + 55; 
            i++; 
        } 
          
        nbr = nbr / 16; 
    } 
        ft_putstr(hexaDeciNum); 
}