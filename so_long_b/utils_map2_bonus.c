/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 12:51:01 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 12:51:01 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_persone_door_position(char **map, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				info->yp = i;
				info->xp = j;
			}
			else if (map[i][j] == 'E')
			{
				info->ydoor = i;
				info->xdoor = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char	**map, int xp, int yp, t_info *info)
{
	int	height;
	int	width;

	height = info->height - 1;
	width = info->width - 1;
	if (xp < 0 || xp >= width || yp < 0
		|| yp >= height || map[yp][xp] == 'M'
		|| map[yp][xp] == '1' || map[yp][xp] == 'S')
	{
		return ;
	}
	else
	{
		map[yp][xp] = 'M';
		flood_fill(map, xp, yp + 1, info);
		flood_fill(map, xp, yp - 1, info);
		flood_fill(map, xp + 1, yp, info);
		flood_fill(map, xp - 1, yp, info);
	}
}

int	check_coins_exit(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_paths(char **map, t_info *info)
{
	get_persone_door_position(map, info);
	get_enemy_position(map, info);
	flood_fill(info->map_cpy, info->xp, info->yp, info);
	if (check_coins_exit(info->map_cpy) == 1)
	{
		free_memory(info->map_cpy, info->height);
		info->map_cpy = NULL;
		return (1);
	}
	return (0);
}
