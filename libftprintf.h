
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_list
{
	va_list			args;
	int				dash;
	int				zero;
	int				width;
	int				prec;
	int				length;
}					t_list;

#endif