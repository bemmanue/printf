
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_eval_space(t_list *tab, int i)
{
	if (!tab->space)
	{
		tab->space = 1;
		tab->length += write(1, " ", 1);
	}
	return (++i);
}

int	ft_type_parsing(t_list *tab, const char *fmt, int i)
{
	if (fmt[i] == 'c')
		ft_print_char(tab);
	else if (fmt[i] == 's')
		ft_print_string(tab);
	else if (fmt[i] == 'p')
		ft_print_pointer(tab);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_integer(tab);
	else if (fmt[i] == 'u')
		ft_print_unsigned_decimal(tab);
	else if (fmt[i] == 'x')
		ft_print_unsigned_hexadecimal_low(tab);
	else if (fmt[i] == 'X')
		ft_print_unsigned_hexadecimal_high(tab);
	else if (fmt[i] == '%')
		ft_print_percent(tab);
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
	tab = ft_clean_flags(tab);
	return (i);
}
