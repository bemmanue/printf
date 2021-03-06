/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_high_x_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:41:01 by bemmanue          #+#    #+#             */
/*   Updated: 2021/06/25 10:41:05 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convertion(char *str, unsigned int n, int i)
{
	str[i--] = '\0';
	while (i >= 0)
	{
		if ((n % 16) > 9)
			str[i] = (n % 16) + 55;
		else
			str[i] = (n % 16) + 48;
		n /= 16;
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
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_high_x_itoa(unsigned int n)
{
	char	*str;

	str = malloc(sizeof(*str) * ft_count(n) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_convertion(str, n, ft_count(n)));
}
