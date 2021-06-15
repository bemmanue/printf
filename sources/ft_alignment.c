
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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
	while (tab->width > len)
	{
		tab->length += write(1, " ", 1);
		len++;
	}
}
