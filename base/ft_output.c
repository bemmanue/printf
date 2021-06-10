
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_list *tab)
{
	char c;

	c = va_arg(tab->args, int);
	write(1, &c, 1);
}

void	ft_print_string(t_list *tab)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(tab->args, char *);
	while (s[i])
		write(1, &s[i++], 1);
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

	i = 0;
	d = va_arg(tab->args, int);
	num = ft_itoa(d);
	while (num[i])
		write(1, &num[i++], 1);
}

void	ft_print_unsigned_decimal(t_list *tab)
{
 	int				i;
 	unsigned int	u;
 	char			*num;

 	i = 0;
 	u = va_arg(tab->args, unsigned int);
 	num = ft_unsigned_itoa(u);
 	while(num[i])
 		write(1, &num[i++], 1);
}

void	ft_print_unsigned_hexadecimal_low(t_list *tab)
{
 	int				i;
 	unsigned int	x;
 	char			*num;

 	i = 0;
	x = va_arg(tab->args, unsigned int);
 	num = ft_low_x_itoa(x);
 	while (num[i])
 		write(1, &num[i++], 1);
}

void	ft_print_unsigned_hexadecimal_high(t_list *tab)
{
	int				i;
	unsigned int	x;
	char			*num;

	i = 0;
	x = va_arg(tab->args, unsigned int);
	num = ft_high_x_itoa(x);
	while (num[i])
		write(1, &num[i++], 1);
}

void	ft_print_percent(void)
{
	write(1, "%", 1);
}