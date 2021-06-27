
#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *str);

int		ft_count_num(int n);

char	*ft_high_x_itoa(unsigned int n);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

char	*ft_itoa(int n);

char	*ft_low_x_itoa(unsigned long n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s1);

size_t	ft_strlen(const char *str);

char	*ft_unsigned_itoa(unsigned int n);

#endif