/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:44:25 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 11:10:05 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_pointer(t_list *tab)
{
	int				i;
	int				len;
	char			*num;
	unsigned long	p;

	i = 0;
	p = va_arg(tab->args, unsigned long);
	num = ft_low_x_itoa(p);
	if (num == NULL)
		return (-1);
	if (p)
		len = ft_strlen(num) + 2;
	else
		len = 2;
	if (tab->prec < 0 && len == 2)
		len++;
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
	tab->length += write(1, "0x", 2);
	while ((p || tab->prec < 0) && num[i])
		tab->length += write(1, &num[i++], 1);
	free(num);
	if ((tab->width > len || tab->prec > len) && tab->dash)
		ft_complete_int(tab, len);
	return (0);
}

int	ft_print_integer(t_list *tab)
{
	int		i;
	int		d;
	int		len;
	char	*num;

	i = 0;
	d = va_arg(tab->args, int);
	if (!d && !tab->prec && !tab->width)
		num = ft_strdup("");
	else if (!d && !tab->prec)
		num = ft_strdup(" ");
	else
		num = ft_itoa(d);
	if (num == NULL)
		return (-1);
	len = ft_strlen(num);
	if (tab->width > len || tab->prec >= len || tab->zero)
		i = ft_align_int(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	free(num);
	if ((tab->width > len || tab->prec > len) && tab->dash)
		ft_complete_int(tab, len);
	return (0);
}

int	ft_print_unsigned_decimal(t_list *tab)
{
	unsigned int	u;
	int				i;
	int				len;
	char			*num;

	i = 0;
	u = va_arg(tab->args, unsigned int);
	if (!u && !tab->prec && !tab->width)
		num = ft_strdup("");
	else if (!u && !tab->prec)
		num = ft_strdup(" ");
	else
		num = ft_unsigned_itoa(u);
	if (num == NULL)
		return (-1);
	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	free(num);
	if (tab->width > len && tab->dash)
		ft_complete_int(tab, len);
	return (0);
}

int	ft_print_unsigned_hexadecimal_low(t_list *tab)
{
	int				i;
	int				len;
	char			*num;
	unsigned int	x;

	i = 0;
	x = va_arg(tab->args, unsigned int);
	if (!x && !tab->prec && !tab->width)
		num = ft_strdup("");
	else if (!x && !tab->prec)
		num = ft_strdup(" ");
	else
		num = ft_low_x_itoa(x);
	if (num == NULL)
		return (-1);
	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	free(num);
	if (tab->width > len && tab->dash)
		ft_complete_int(tab, len);
	return (0);
}

int	ft_print_unsigned_hexadecimal_high(t_list *tab)
{
	int				i;
	int				len;
	char			*num;
	unsigned int	x;

	i = 0;
	x = va_arg(tab->args, unsigned int);
	if (!x && !tab->prec && !tab->width)
		num = ft_strdup("");
	else if (!x && !tab->prec)
		num = ft_strdup(" ");
	else
		num = ft_high_x_itoa(x);
	if (num == NULL)
		return (-1);
	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	free(num);
	if (tab->width > len && tab->dash)
		ft_complete_int(tab, len);
	return (0);
}
