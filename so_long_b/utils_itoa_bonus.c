/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_itoa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 12:50:37 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 12:50:37 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (dstsize != 0)
	{
		while (j < dstsize - 1 && src[j] != '\0')
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

static	int	ft_count(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (i);
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*min_int(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	int		i;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (min_int());
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	count = ft_count(n) + i;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (i == 1)
		str[0] = '-';
	while ((count-- - i) != 0)
	{
		str[count] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
