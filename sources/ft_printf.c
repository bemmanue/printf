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
#include "../libft/libft.h"

t_list	*ft_clean_flags(t_list *tab)
{
	tab->space = 0;
	tab->dash = 0;
	tab->zero = 0;
	tab->width = 0;
	tab->prec = -1;
	return (tab);
}

t_list	*ft_init(t_list *tab)
{
	tab->space = 0;
	tab->dash = 0;
	tab->zero = 0;
	tab->width = 0;
	tab->prec = -1;
	tab->length = 0;
	return (tab);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		len;
	t_list	*tab;

	i = 0;
	len = 0;
	tab = (t_list *)malloc(sizeof(t_list));
	if (!tab)
		return (-1);
	tab = ft_init(tab);
	va_start(tab->args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i = ft_parsing(tab, fmt, ++i);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(tab->args);
	len += tab->length;
	free(tab);
	return (len);
}
