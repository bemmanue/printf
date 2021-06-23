
#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int n);

int		ft_atoi(const char *str);

char	*ft_low_x_itoa(unsigned long n);

char	*ft_high_x_itoa(unsigned int n);

char	*ft_unsigned_itoa(unsigned int n);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

size_t	ft_strlen(const char *str);

int		ft_count_num(int n);


#endif