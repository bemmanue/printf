#include "libft.h"

int	ft_atoi(const char *str)
{
	int	min;
	int	nbr;
	int	dgt;

	min = 0;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			min++;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		dgt = *str++ - 48;
		nbr += dgt;
	}
	if (min)
		nbr = -nbr;
	return (nbr);
}