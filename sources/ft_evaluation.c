
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_eval_width(t_list *tab, const char *fmt, int i)
{
	int	w;

	w = 0;
	if (ft_isdigit(fmt[i]))
		w = ft_atoi(&fmt[i]);
	tab->width = w;
	return (++i);
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