
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

t_list	*ft_init(t_list *tab);

int 	ft_parsing(t_list *tab, const char *fmt, int i);

int		ft_type_parsing(t_list *tab, const char *fmt, int i);

int		ft_eval_dash(t_list *tab, const char *fmt, int i);

int		ft_eval_width(t_list *tab, const char *fmt, int i);

void	ft_print_char(t_list *tab);

void	ft_print_string(t_list *tab);

void	ft_print_pointer(t_list *tab);

void	ft_print_integer(t_list *tab);

void	ft_print_unsigned_hexadecimal_low(t_list *tab);

void	ft_print_unsigned_hexadecimal_high(t_list *tab);

void	ft_print_unsigned_decimal(t_list *tab);

void	ft_print_percent(t_list *tab);

void	ft_right_alignment(t_list *tab, int len);

void	ft_left_alignment(t_list *tab, int len);


#endif