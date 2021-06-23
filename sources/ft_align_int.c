
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_null_again(t_list *tab, int len)
{
	int p;

	p = tab->prec;
	while (p > len)
	{
		tab->length += write(1, "0", 1);
		p--;
	}
}

void	ft_print_null(t_list *tab, int len)
{
	int w;
	int p;

	w = tab->width;
	p = tab->prec;
	while (w > p && w > len)
	{
		tab->length += write(1, "0", 1);
		w--;
	}
}

void	ft_print_space(t_list *tab, int len)
{
	int w;
	int p;

	w = tab->width;
	p = tab->prec;
	while (w > p && w > len)
	{
		tab->length += write(1, " ", 1);
		w--;
	}
}

int	ft_align_int(t_list *tab, int len, char *num)
{
	int i;

	i = 0;
	if (num[i] == '-' && tab->prec >= len)
		tab->prec++;
	if (num[i] == '-' && (tab->width < len || tab->prec > tab->width))
		tab->length += write(1, &num[i++], 1);
	else if (num[i] == '-' && (tab->zero && (tab->prec > tab->width || tab->prec < 0)))
		tab->length += write(1, &num[i++], 1);
	if (tab->width > tab->prec && !(tab->dash))
	{
		if (tab->zero && tab->width && tab->prec < 0)
			ft_print_null(tab, len);
		else
			ft_print_space(tab, len);
	}
	if (num[i] == '-')
		tab->length += write(1, &num[i++], 1);
	if (tab->prec > len)
		ft_print_null_again(tab, len);
	return (i);
}

void	ft_complete_int(t_list *tab, int len)
{
	int w;
	int p;

	w = tab->width;
	p = tab->prec;
	if (w > len && p > len)
		w -= p - len;
	while (w > len)
	{
		tab->length += write(1, " ", 1);
		w--;
	}
}
