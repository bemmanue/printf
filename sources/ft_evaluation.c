
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_eval_zero(t_list *tab, int i)
{
	if (tab->dash == 1)
		tab->zero = 0;
	else
		tab->zero = 1;
	return (++i);
}

int ft_eval_star(t_list *tab, int i)
{
	int w;

	w = va_arg(tab->args, int);
	tab->width = w;
	return (++i);
}

int ft_eval_precision(t_list *tab, const char *fmt, int i)
{
	int p;

	tab->prec = 0;
	i++;
	if (ft_isdigit(fmt[i]))
	{
		p = ft_atoi(&fmt[i]);
		tab->prec = p;
	}
	else if (fmt[i] == '*')
	{
		p = va_arg(tab->args, int);
		tab->prec = p;
	}
	return (++i);
}

int	ft_eval_width(t_list *tab, const char *fmt, int i)
{
	int	w;

	w = 0;
	if (ft_isdigit(fmt[i]))
	{
		w = ft_atoi(&fmt[i]);
		i++;
	}
	tab->width = w;
	return (i);
}

int	ft_eval_dash(t_list *tab, const char *fmt, int i)
{
	tab->dash = 1;
	tab->zero = 0;
	while (fmt[i] == '-')
		i++;
	ft_eval_width(tab, fmt, i);
	return (i);
}
