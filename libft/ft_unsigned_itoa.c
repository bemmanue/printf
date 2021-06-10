
#include "libft.h"

static char	*ft_convertion(char *str, unsigned int n, int i)
{
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}

static int	ft_count(unsigned int n)
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

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;

	str = malloc(sizeof(*str) * ft_count(n) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_convertion(str, n, ft_count(n)));
}