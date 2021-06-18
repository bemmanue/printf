
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_pointer(t_list *tab)
{
	unsigned long	p;
	int				i;
	char			*num;
	char			*index;
	int				len;

	i = 0;
	p = va_arg(tab->args, unsigned long);
 	num = ft_low_x_itoa(p);
 	index = ft_output_address(num);
	len = ft_strlen(index);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, index);
	while (index[i])
		tab->length += write(1, &index[i++], 1);
	if ((tab->width > len || tab->prec > len) && tab->dash)
		ft_complete_int(tab, len);
	tab = ft_clean_flags(tab);
}

void	ft_print_integer(t_list *tab)
{
	int 	i;
	int		d;
	char	*num;
	int 	len;

	i = 0;
	d = va_arg(tab->args, int);
	num = ft_itoa(d);
	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	if ((tab->width > len || tab->prec > len) && tab->dash)
		ft_complete_int(tab, len);
	tab = ft_clean_flags(tab);
}

void	ft_print_unsigned_decimal(t_list *tab)
{
 	int				i;
 	unsigned int	u;
 	char			*num;
 	int				len;

 	i = 0;
 	u = va_arg(tab->args, unsigned int);
 	num = ft_unsigned_itoa(u);
 	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
 	while(num[i])
		tab->length += write(1, &num[i++], 1);
	if (tab->width > len && tab->dash)
		ft_complete_int(tab, len);
	tab = ft_clean_flags(tab);
}

void	ft_print_unsigned_hexadecimal_low(t_list *tab)
{
 	int				i;
 	unsigned int	x;
 	char			*num;
 	int 			len;

 	i = 0;
	x = va_arg(tab->args, unsigned int);
 	num = ft_low_x_itoa(x);
 	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
 	while (num[i])
		tab->length += write(1, &num[i++], 1);
	if (tab->width > len && tab->dash)
		ft_complete_int(tab, len);
	tab = ft_clean_flags(tab);
}

void	ft_print_unsigned_hexadecimal_high(t_list *tab)
{
	int				i;
	unsigned int	x;
	char			*num;
	int 			len;

	i = 0;
	x = va_arg(tab->args, unsigned int);
	num = ft_high_x_itoa(x);
	len = ft_strlen(num);
	if (tab->width > len || tab->prec > len)
		i = ft_align_int(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	if (tab->width > len && tab->dash)
		ft_complete_int(tab, len);
	tab = ft_clean_flags(tab);
}
