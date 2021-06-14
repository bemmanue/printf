/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:25:38 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/03 13:25:41 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_list	*ft_init(t_list *tab)
{
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
	int 	len;
	t_list	*tab;

	i = 0;
	len = 0;
	tab = (t_list *)malloc(sizeof(t_list));
	if (!tab)
		return (-1);
	tab = ft_init(tab);
	va_start(tab->args, fmt);
	while(fmt[i])
	{
		if (fmt[i] == '%')
			i = ft_parsing(tab, fmt, ++i);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(tab->args);
	len += tab->length;
	return (len);
}

int	main(void)
{
	char	c;
	char	*str;
	int 	d;

	c = 'U';
	str = "cat";
	d = 555;

	printf("%d", ft_printf("hello %-8c %-5c", c, c));
	printf("\n");
	printf("%d", printf("hello %-8c %-5c", c, c));
	return (0);
}