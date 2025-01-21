/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 12:52:10 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 12:52:10 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_moves(t_info	*info, int x, int y)
{
	if (info->map[y][x] != '1')
	{
		if (info->map[y][x] == 'C')
			info->coin -= 1;
		info->map[info->yp][info->xp] = '0';
		info->xp = x;
		info->yp = y;
		info->map[y][x] = 'P';
		info->move_count += 1;
		if (x == info->xenemy && y == info->yenemy)
		{
			free_memory(info->map, info->height);
			free_memory(info->map_cpy, info->height);
			exit(1);
		}
		if (x == info->xdoor && y == info->ydoor && info->coin == 0)
		{
			free_memory(info->map, info->height);
			free_memory(info->map_cpy, info->height);
			exit(1);
		}
	}
	render_all_map(info);
}

int	handle_keys(int keycode, void *info)
{
	t_info	*actule_info;
	int		x;	
	int		y;

	actule_info = (t_info *)info;
	x = actule_info->xp;
	y = actule_info->yp;
	if (keycode == 53)
	{
		free_memory(actule_info->map, actule_info->height);
		free_memory(actule_info->map_cpy, actule_info->height);
		exit(1);
	}
	else if (keycode == 13)
		y--;
	else if (keycode == 1)
		y++;
	else if (keycode == 2)
		x++;
	else if (keycode == 0)
		x--;
	if (x != actule_info->xp || y != actule_info->yp)
		handle_moves(actule_info, x, y);
	return (0);
}

int	handle_animation(t_info *info)
{
	if (info->timer > 5)
	{
		info->frame = (info->frame + 1) % 6;
		info->timer = 0;
	}
	if (info->enemy == 1 && info->move_timer == 30)
	{
		handle_enemy_movement(info, &info->enemy_direction);
		info->move_timer = 0;
	}
	info->timer++;
	info->move_timer++;
	render_all_map(info);
	return (0);
}

void	render_door(t_info *info)
{
	if (info->coin == 0)
		put_img(info, info->door_open, info->xdoor, info->ydoor);
	else
		put_img(info, info->door_close, info->xdoor, info->ydoor);
}

void	render_text(t_info *info)
{
	char	*str_moves;

	str_moves = ft_itoa(info->move_count);
	mlx_string_put(info->mlx, info->window, 15, 15, 0xFFFFFF, str_moves);
	free(str_moves);
}
