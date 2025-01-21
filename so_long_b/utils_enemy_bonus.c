/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 13:37:06 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 13:37:06 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_enemy_position(char **map, t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (map[y][x] == 'S')
			{
				info->xenemy = x;
				info->yenemy = y;
			}
			x++;
		}
		y++;
	}
}

static	void	move_top(t_info *info, int x, int y)
{
	info->map[y][x] = '0';
	info->yenemy = y - 1;
	if (info->map[y - 1][x] == 'P')
	{
		free_memory(info->map, info->height);
		free_memory(info->map_cpy, info->height);
		exit(1);
	}
	info->map[y - 1][x] = 'S';
}

static	void	move_down(t_info *info, int x, int y)
{
	info->map[y][x] = '0';
	info->yenemy = y + 1;
	if (info->map[y + 1][x] == 'P')
	{
		free_memory(info->map, info->height);
		free_memory(info->map_cpy, info->height);
		exit(1);
	}
	info->map[y + 1][x] = 'S';
}

void	handle_enemy_movement(t_info *info, char *direction)
{
	int	x;
	int	y;

	y = info->yenemy;
	x = info->xenemy;
	if (*direction == 'T')
	{
		if (info->map[y + 1][x] == '1' || info->map[y + 1][x] == 'C'
		|| (x == info->xdoor && (y + 1) == info->ydoor))
			*direction = 'D';
		else
			move_down(info, x, y);
	}
	if (*direction == 'D')
	{
		if (info->map[y - 1][x] == '1' || info->map[y - 1][x] == 'C'
		|| info->map[y - 1][x] == 'E')
			*direction = 'T';
		else
			move_top(info, x, y);
	}
}
