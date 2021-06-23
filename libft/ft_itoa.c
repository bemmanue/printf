
#include "libft.h"

static char	*ft_neg(char *str, int n, int i)
{
	str[i] = '\0';
	i--;
	if (i >= 0)
	{
		str[0] = '-';
		while (i > 0)
		{
			str[i] = -(n % 10) + 48;
			n /= 10;
			i--;
		}
	}
	free(str);
	return (str);
}

static char	*ft_pos(char *str, int n, int i)
{
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	free(str);
	return (str);
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (++i);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(sizeof(*str) * ft_count(n) + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	if (n < 0)
		return (ft_neg(str, n, ft_count(n)));
	else
		return (ft_pos(str, n, ft_count(n)));
}