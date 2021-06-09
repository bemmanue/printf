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

#include "libftprintf.h"

t_list	*ft_initialise(t_list *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->prec = -1;
	return (flags);
}

void	ft_print_char(t_list *flags)
{
	char c;

	c = va_arg(flags->args, int);
	write(1, &c, 1);

}

void	ft_print_string(t_list *flags)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(flags->args, char *);
	while (s[i])
		write(1, &s[i++], 1);
}

int	ft_evaluate_variable(t_list *flags, const char *fmt, int i)
{
	if (fmt[i] == 'c')
		ft_print_char(flags);
	if(fmt[i] == 's')
		ft_print_string(flags);
/*	else if(fmt[i] == 'p')
		ft_print_pointer(flags);
	else if(fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_integer(flags);
	else if(fmt[i] == 'u')
		ft_print_unsigned_decimal(flags);
	else if(fmt[i] == 'x' || fmt[i] == 'X')
		ft_print_unsigned_hexadecimal(flags);
	else if(fmt[i] == '%')
		ft_print_persent(flags);*/
	return (++i);
}

void	ft_evaluate_format(t_list *flags, const char *fmt, int i)
{
	while(fmt[i++])
	{
		if (fmt[i] == '-')
			flags->dash = 1;
//		else if (fmt[i]) == '0')
	//		flags->zero = 1;
		else if (fmt[i] == '.')
			flags->width = 1;
		else if (fmt[i] == '*')
			flags->prec = 0;
		else
			break;
	}
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int 	ret;
	t_list	*flags;

	i = 0;
	ret = 0;
	flags = (t_list *)malloc(sizeof(t_list));
	if (!flags)
		return (-1);
	flags = ft_initialise(flags);
	va_start(flags->args, fmt);
	while(fmt[i])
	{
		if (fmt[i] == '%')
			i = ft_evaluate_variable(flags, fmt, i + 1);
		else
			ret += write(1, &fmt[i], 1);
		i++;
	}
	va_end(flags->args);
	ret += flags->length;
	free(flags);
	return (ret);
}

int	main(void)
{
	char	*str;
	char	c;

	c = 'U';
	str = "Kamil";
	ft_printf("hello %s hello %c", str, c);
	return (0);
}
