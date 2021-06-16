
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_string(t_list *tab)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	s = va_arg(tab->args, char *);
	len = ft_strlen(s);
//	if (tab->width > len && !(tab->dash))
//		ft_right_alignment(tab, len);
	while (s[i])
		tab->length += write(1, &s[i++], 1);
	if (tab->width > len && tab->dash)
		ft_left_alignment(tab, len);
	tab->width = 0;
	tab->dash = 0;
}

void	ft_print_char(t_list *tab)
{
	char c;

	c = va_arg(tab->args, int);
//	if (tab->width > 1 && !(tab->dash))
//		ft_right_alignment(tab, 1);
	tab->length += write(1, &c, 1);
	if (tab->width > 1 && tab->dash)
		ft_left_alignment(tab, 1);
	tab->width = 0;
	tab->dash = 0;
}

/*
void	ft_print_pointer(t_list *tab)
{
	char			num;
	unsigned long	p;
	&p = va_arg(tab->args, unsigned long);
 	num = ft_itoa(d);
	//(unsigned long)va_arg(args, void *);
}
*/

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
		i = ft_check_alignment(tab, len, num);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	if ((tab->width > len || tab->prec > len) && tab->dash)
		ft_left_alignment(tab, len);
	tab->width = 0;
	tab->dash = 0;
	tab->prec = 0;
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
	if (tab->zero)
		tab->zero = 0;
//	if (tab->width > len || tab->prec > len)
//		ft_check_alignment(tab, len);
 	while(num[i])
		tab->length += write(1, &num[i++], 1);
	if (tab->width > len && tab->dash)
		ft_left_alignment(tab, len);
	tab->width = 0;
	tab->dash = 0;
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
	if (tab->zero)
		tab->zero = 0;
//	if (tab->width > len || tab->prec > len)
//		ft_check_alignment(tab, len);
 	while (num[i])
		tab->length += write(1, &num[i++], 1);
	if (tab->width > len && tab->dash)
		ft_left_alignment(tab, len);
	tab->width = 0;
	tab->dash = 0;
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
	if (tab->zero)
		tab->zero = 0;
//	if (tab->width > len || tab->prec > len)
//		ft_check_alignment(tab, len);
	while (num[i])
		tab->length += write(1, &num[i++], 1);
	if (tab->width > len && tab->dash)
		ft_left_alignment(tab, len);
	tab->width = 0;
	tab->dash = 0;
}

void	ft_print_percent(t_list *tab)
{
//	if (tab->width > 1 || tab->prec > 1)
//		ft_check_alignment(tab, 1);
	tab->length += write(1, "%", 1);
	if (tab->width > 1 && tab->dash)
		ft_left_alignment(tab, 1);
	tab->width = 0;
	tab->dash = 0;
}