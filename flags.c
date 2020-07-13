/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:54:50 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/13 12:47:52 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Fonction qui recupere la precision
// - Si la precision est suivi d'une etoile on recupere l'argument et en remplis l'int dot (la precision) de la structure
// - Si la precision est suivi de digits directement dans le format on remplis l'int dot avec leur valeur total

void	conv_flag_dot(char *str, va_list *args, t_struct *strct)
{
	strct->index++;
	strct->dot = 1;
	if (str[strct->index] == '*')
	{
		strct->prec = va_arg(*args, int);
		strct->index++;
	}
	while (ft_isdigit(str[strct->index]))
	{
		strct->prec = (strct->prec * 10) + (str[strct->index] - '0');
		strct->index++;
	}
}

// Fonction traitement du left alignement '-'
// - On met minus a 1 pour prendre en compte le left alignemnet
// - On met zero a 0 car le left alignement ne marche pas avec 0, zero doit etre pris en compte seulement si l'alignement est right

void	conv_flag_minus(t_struct *strct)
{
	strct->minus = 1;
	strct->zero = 0;
}

// Fonction de traitement d'un star '*'
// - On recupere l'argument de star et on remplis son int avec cette valeur;

void	conv_flag_star(va_list *args, t_struct *strct)
{
	strct->width = va_arg(*args, int);
	strct->star = 1;
}

// Fonction de traitement des digits
// - Si on a deja recuperer une valeur avec star on remet width a 0
// - On parcour les digits et en remplissant width de leur valeur

void	conv_flag_digit(char c, t_struct *strct)
{
	if (strct->star == 1)
		strct->width = 0;
	strct->width = (strct->width * 10) + (c - '0');
}
