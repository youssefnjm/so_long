/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 17:01:14 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-10 17:01:14 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (x == info->xdoor && y == info->ydoor && info->coin == 0)
		{
			ft_putnbr(info->move_count);
			write(1, "\n", 1);
			free_memory(info->map, info->height);
			free_memory(info->map_cpy, info->height);
			exit(1);
		}
		ft_putnbr(info->move_count);
		write(1, "\n", 1);
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

void	render_door(t_info *info)
{
	if (info->coin == 0)
		put_img(info, info->door_open, info->xdoor, info->ydoor);
	else
		put_img(info, info->door_close, info->xdoor, info->ydoor);
}

int	destroy_window(void *info)
{
	t_info	*actual_info;

	actual_info = info;
	free_memory(actual_info->map, actual_info->height);
	free_memory(actual_info->map_cpy, actual_info->height);
	exit(1);
}
