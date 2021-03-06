/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:43:59 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:44:04 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_eval_zero(t_list *tab, int i)
{
	if (tab->dash == 1)
		tab->zero = 0;
	else
		tab->zero = 1;
	return (++i);
}

int	ft_eval_star(t_list *tab, int i)
{
	int	w;

	w = va_arg(tab->args, int);
	if (w < 0)
	{
		w *= -1;
		tab->dash = 1;
	}
	tab->width = w;
	return (++i);
}

int	ft_eval_precision(t_list *tab, const char *fmt, int i)
{
	int	p;

	tab->prec = 0;
	i++;
	while (fmt[i] == '0')
		i++;
	if (ft_isdigit(fmt[i]))
	{
		p = ft_atoi(&fmt[i]);
		tab->prec = p;
		i += ft_count_num(p);
	}
	else if (fmt[i] == '*')
	{
		p = va_arg(tab->args, int);
		if (p < 0)
			p = -1;
		tab->prec = p;
		i++;
	}
	return (i);
}

int	ft_eval_width(t_list *tab, const char *fmt, int i)
{
	int	w;

	w = 0;
	if (ft_isdigit(fmt[i]))
		w = ft_atoi(&fmt[i]);
	tab->width = w;
	i += ft_count_num(w);
	return (i);
}

int	ft_eval_dash(t_list *tab, const char *fmt, int i)
{
	tab->dash = 1;
	if (tab->zero == 1)
		tab->zero = 0;
	while (fmt[i] == '-')
		i++;
	ft_eval_width(tab, fmt, i);
	return (i);
}
