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
			ft_parser(tab, fmt, ++i);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(tab->args);
	return (len);
}

int	main(void)
{
	char	c;
	char	*str;
	int 	d;

	c = 'U';
	str = "Yulya";
	d = 2341;

//	ft_printf("hello %c\n", c);
	printf("%*s", 5, str);
	return (0);
}