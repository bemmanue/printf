/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:43:22 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:43:27 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_align_char(t_list *tab, int len)
{
	int	w;
	int	p;
	int	i;

	w = tab->width;
	p = tab->prec;
	if ((w > p && p >= 0) || w > len)
	{
		if (p > len || p < 0 || (len == 1 && !p))
			i = w - len;
		else
			i = w - p;
		if (tab->zero)
			while (i--)
				tab->length += write(1, "0", 1);
		else
			while (i--)
				tab->length += write(1, " ", 1);
	}
}

void	ft_complete_char(t_list *tab, int len)
{
	int	w;
	int	p;
	int	i;

	w = tab->width;
	p = tab->prec;
	if (w > len || (w > p && p >= 0))
	{
		if (len == 1 && !p)
			i = w - len;
		else if (len > p && p >= 0)
			i = w - p;
		else
			i = w - len;
		while (i--)
			tab->length += write(1, " ", 1);
	}
}
