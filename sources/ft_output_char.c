/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:44:12 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:44:16 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_string(t_list *tab)
{
	char	*s;
	int		i;
	int		len;
	int		p;

	i = 0;
	p = tab->prec;
	s = va_arg(tab->args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (tab->width && !tab->dash)
		ft_align_char(tab, len);
	if (p < 0)
		while (s[i])
			tab->length += write(1, &s[i++], 1);
	else
		while (s[i] && p--)
			tab->length += write(1, &s[i++], 1);
	if (tab->width && tab->dash)
		ft_complete_char(tab, len);
}

void	ft_print_char(t_list *tab)
{
	char	c;
	int		len;

	len = 1;
	c = va_arg(tab->args, int);
	if (tab->width && !tab->dash)
		ft_align_char(tab, len);
	tab->length += write(1, &c, 1);
	if (tab->width && tab->dash)
		ft_complete_char(tab, len);
}

void	ft_print_percent(t_list *tab)
{
	int	len;

	len = 1;
	if (tab->width && !tab->dash)
		ft_align_char(tab, len);
	tab->length += write(1, "%", 1);
	if (tab->width && tab->dash)
		ft_complete_char(tab, len);
}
