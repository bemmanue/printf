
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_check_alignment(t_list *tab, int len)
{
	int w;
	int p;

	w = tab->width;
	p = tab->prec;
	if (tab->width > tab->prec && !(tab->dash))
	{
		if (tab->zero)
		{
			while (w > p && w > len)
			{
				tab->length += write(1, "0", 1);
				w--;
			}
		}
		else
		{
			while (w > p && w > len)
			{
				tab->length += write(1, " ", 1);
				w--;
			}
		}
	}
	if (tab->prec > len)
	{
		while (p > len)
		{
			tab->length += write(1, "0", 1);
			p--;
		}
	}
}

void	ft_add_zero(t_list *tab, int len)
{
	while (tab->width > len)
	{
		tab->length += write(1, "0", 1);
		len++;
	}
}

void	ft_right_alignment(t_list *tab, int len)
{
	while (tab->width > len)
	{
		tab->length += write(1, " ", 1);
		len++;
	}
}

void	ft_left_alignment(t_list *tab, int len)
{
	if (tab->width > len && tab->prec > len)
		tab->width -= tab->prec - len;
	while (tab->width > len)
	{
		tab->length += write(1, " ", 1);
		len++;
	}
}
