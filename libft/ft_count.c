
#include "libft.h"

int	ft_count_num(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (++i);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}