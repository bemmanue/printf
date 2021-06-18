
#include "libft.h"

static char	*ft_convertion(char *str, unsigned long n, int i)
{
	str[i--] = '\0';
	while (i >= 0)
	{
		if ((n % 16) > 9)
			str[i] = (n % 16) + 87;
		else
			str[i] = (n % 16) + 48;
		n /= 16;
		i--;
	}
	return (str);
}

static int	ft_count(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
		return (++i);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_low_x_itoa(unsigned long n)
{
	char	*str;

	str = malloc(sizeof(*str) * ft_count(n) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_convertion(str, n, ft_count(n)));
}
