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

t_list *ft_clean_flags(t_list *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->width = 0;
	tab->prec = -1;
	return (tab);
}

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
make fclean
int	main(void)
{
	char	c;
	char	*s;
	int 	d;
	int		l;
	int		i;
	char	*p;
	unsigned int u;
	unsigned int x;

	l = 5;
	c = 'U';
	s = "myaushenka";
	d = 1111111;
	i = 7;
	p = "myaushenka";
	u = 1234567;
	x = 1234567890;

	printf("%d", ft_printf("%*.1s", 25, s));
	printf("\n");
	printf("%d", printf("%*.1s", 25, s));
	return (0);
}