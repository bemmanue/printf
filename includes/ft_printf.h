
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct		s_list
{
	va_list			args;
	int				dash;
	int				zero;
	int				width;
	int				prec;
	int				length;
}					t_list;

int		ft_printf(const char *fmt, ...);

void	ft_print_char(t_list *tab);

void	ft_print_string(t_list *tab);

void	ft_print_pointer(t_list *tab);

void	ft_print_integer(t_list *tab);

void	ft_print_unsigned_hexadecimal_low(t_list *tab);

void	ft_print_unsigned_hexadecimal_high(t_list *tab);

void	ft_print_unsigned_decimal(t_list *tab);

void	ft_print_percent(void);

void	ft_parser(t_list *tab, const char *fmt, int i);

#endif