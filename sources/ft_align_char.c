
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_align_char(t_list *tab, int len)
{
	int w;
	int p;
	int i;

	w = tab->width;
	p = tab->prec;
	if (p > len || p < 0)
		i = w - len;
	else
		i = w - p;
	while (i--)
		tab->length += write(1, " ", 1);
}

void	ft_complete_char(t_list *tab, int len)
{
	int w;
	int p;
	int i;

	w = tab->width;
	p = tab->prec;
	if (len > p && p >= 0)
		i = w - p;
	else
		i = w - len;
	while (i--)
		tab->length += write(1, " ", 1);
}
