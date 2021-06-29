/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:45:06 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:45:11 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_passing(const char *fmt, t_list *tab, int *len)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i = ft_parsing(tab, fmt, ++i);
			if (i < 0)
				return (-1);
		}
		else
			*len += write(1, &fmt[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	t_list	*tab;

	len = 0;
	tab = (t_list *)malloc(sizeof(t_list));
	if (!tab)
		return (-1);
	ft_init_flags(&tab);
	va_start(tab->args, fmt);
	if (ft_passing(fmt, tab, &len) < 0)
	{
		free(tab);
		va_end(tab->args);
		return (-1);
	}
	va_end(tab->args);
	len += tab->length;
	free(tab);
	return (len);
}
