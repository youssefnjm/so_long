/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 12:51:18 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 12:51:18 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_memory(char **map, int i)
{
	if (map)
	{
		while (i >= 0)
		{
			free(map[i]);
			i--;
		}
		free(map);
	}
}

char	**ft_safe_malloc_map(t_info *info)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (info->height + 1));
	if (!str)
		return (NULL);
	while (i < info->height)
	{
		str[i] = malloc(sizeof(char) * (info->width + 1));
		if (!str[i])
			return (free_memory(str, i), str = NULL, NULL);
		i++;
	}
	return (str);
}

int	destroy_window(void *info)
{
	t_info	*actual_info;

	actual_info = info;
	free_memory(actual_info->map, actual_info->height);
	free_memory(actual_info->map_cpy, actual_info->height);
	exit(1);
}
