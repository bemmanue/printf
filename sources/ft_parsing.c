/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:44:41 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:44:45 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_eval_space(t_list *tab, int i)
{
	if (!tab->space)
	{
		tab->space = 1;
		tab->length += write(1, " ", 1);
	}
	return (++i);
}

static int	ft_type_parsing(t_list *tab, const char *fmt, int i)
{
	int	check;

	check = 0;
	if (fmt[i] == 'c')
		ft_print_char(tab);
	else if (fmt[i] == 's')
		ft_print_string(tab);
	else if (fmt[i] == 'p')
		check = ft_print_pointer(tab);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		check = ft_print_integer(tab);
	else if (fmt[i] == 'u')
		check = ft_print_unsigned_decimal(tab);
	else if (fmt[i] == 'x')
		check = ft_print_unsigned_hexadecimal_low(tab);
	else if (fmt[i] == 'X')
		check = ft_print_unsigned_hexadecimal_high(tab);
	else if (fmt[i] == '%')
		ft_print_percent(tab);
	if (check < 0)
		return (-1);
	return (i);
}

int	ft_parsing(t_list *tab, const char *fmt, int i)
{
	while (!(ft_isalpha(fmt[i]) || fmt[i] == '%'))
	{
		if (fmt[i] == ' ')
			i = ft_eval_space(tab, i);
		if (fmt[i] == '-')
			i = ft_eval_dash(tab, fmt, i);
		if (fmt[i] == '0')
			i = ft_eval_zero(tab, i);
		if (fmt[i] == '.')
			i = ft_eval_precision(tab, fmt, i);
		if (fmt[i] == '*')
			i = ft_eval_star(tab, i);
		if (ft_isdigit(fmt[i]))
			i = ft_eval_width(tab, fmt, i);
	}
	i = ft_type_parsing(tab, fmt, i);
	ft_clean_flags(&tab);
	return (i);
}
