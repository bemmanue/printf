
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_evaluate_variable(t_list *tab, const char *fmt, int i)
{
	if (fmt[i] == 'c')
		ft_print_char(tab);
	else if (fmt[i] == 's')
		ft_print_string(tab);
/*	else if (fmt[i] == 'p')
		ft_print_pointer(tab); */
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_integer(tab);
	else if (fmt[i] == 'u')
		ft_print_unsigned_decimal(tab);
	else if (fmt[i] == 'x')
		ft_print_unsigned_hexadecimal_low(tab);
	else if (fmt[i] == 'X')
		ft_print_unsigned_hexadecimal_high(tab);
	else if (fmt[i] == '%')
		ft_print_percent();
}

void	ft_parser(t_list *tab, const char *fmt, int i)
{
	while (!(ft_isalpha(fmt[i]) || fmt[i] == '%'))
	{
		if (fmt[i] == '-')
			tab->dash = 1;
//		else if (fmt[i]) == '0')
//			tab->zero = 1;
		else if (fmt[i] == '.')
			tab->width = 1;
		else if (fmt[i] == '*')
			tab->prec = 1;
		i++;
	}
	ft_evaluate_variable(tab, fmt, i);
}
