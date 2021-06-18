
#include "libft.h"

char	*ft_output_address(char *num)
{
	int		i;
	int		len;
	char	*prefix;
	char	*index;

	i = 0;
	len = ft_strlen(num);
	index = malloc(sizeof(*index) * (len + 1));
	if (!index)
		return (NULL);
	prefix = "0x";
	while (*prefix)
		index[i++] = *prefix++;
	if (!num)
		index[i] = '0';
	while (len--)
		index[i++] = *num++;
	index[i] = '\0';
	return (index);
}