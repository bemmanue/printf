/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:39:30 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:39:37 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				space;
	int				dash;
	int				zero;
	int				width;
	int				prec;
	int				length;
}					t_list;

int		ft_printf(const char *fmt, ...);

void	ft_init(t_list **tab);

void	ft_clean_flags(t_list **tab);

int 	ft_parsing(t_list *tab, const char *fmt, int i);

int		ft_type_parsing(t_list *tab, const char *fmt, int i);

int		ft_eval_dash(t_list *tab, const char *fmt, int i);

int		ft_eval_width(t_list *tab, const char *fmt, int i);

int		ft_eval_precision(t_list *tab, const char *fmt, int i);

int		ft_eval_zero(t_list *tab, int i);

int		ft_eval_star(t_list *tab, int i);

void	ft_print_char(t_list *tab);

void	ft_print_string(t_list *tab);

int 	ft_print_pointer(t_list *tab);

int 	ft_print_integer(t_list *tab);

int 	ft_print_unsigned_hexadecimal_low(t_list *tab);

int 	ft_print_unsigned_hexadecimal_high(t_list *tab);

int 	ft_print_unsigned_decimal(t_list *tab);

void	ft_print_percent(t_list *tab);

int 	ft_align_int(t_list *tab, int len, char *num);

void	ft_align_char(t_list *tab, int len);

void	ft_complete_int(t_list *tab, int len);

void	ft_complete_char(t_list *tab, int len);

void	ft_print_null(t_list *tab, int len);

void	ft_print_null_again(t_list *tab, int len);

void	ft_print_space(t_list *tab, int len);


#endif
