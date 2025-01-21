/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 21:30:21 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-08 21:30:21 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_floor(t_info *info)
{
	int	x;
	int	y;

	y = 1;
	while (y < info->height - 1)
	{
		x = 1;
		while (x < info->width - 1)
		{
			if (info->map_cpy[y][x] == '1')
				put_img(info, info->block, x, y);
			if (info->map_cpy[y][x] == 'M' || info->map_cpy[y][x] == '0')
				put_img(info, info->floor, x, y);
			x++;
		}
		y++;
	}
}

void	render_walls(t_info *info)
{
	int	x;
	int	y;
	int	max_w;
	int	max_h;

	x = 0;
	y = 0;
	max_w = info->width - 1;
	max_h = info->height - 1;
	while (x < info->width)
	{
		put_img(info, info->wall_top, x, 0);
		put_img(info, info->wall_top, x, max_h);
		x++;
	}
	while (y < info->height)
	{
		put_img(info, info->wall_side, 0, y);
		put_img(info, info->wall_side, max_w, y);
		y++;
	}
	put_img(info, info->wall_top_left, 0, 0);
	put_img(info, info->wall_top_right, max_w, 0);
	put_img(info, info->wall_bottom_left, 0, max_h);
	put_img(info, info->wall_bottom_right, max_w, max_h);
}

void	render_charachters(t_info *info)
{
	int	x;
	int	y;

	y = 1;
	while (y < info->height - 1)
	{
		x = 1;
		while (x < info->width - 1)
		{
			if (info->map[y][x] == 'P')
				put_img(info, info->player, x, y);
			else if (info->map[y][x] == 'C')
				put_img(info, info->collectible, x, y);
			x++;
		}
		y++;
	}
}

int	render_all_map(t_info *info)
{
	if (init_images(info) == 1)
		return (1);
	render_walls(info);
	render_floor(info);
	render_door(info);
	render_charachters(info);
	return (0);
}

int	render_game(t_info *info)
{
	int	height_w;
	int	width_w;

	height_w = info->height * 50;
	width_w = info->width * 50;
	info->move_count = 0;
	info->mlx = mlx_init();
	if (!info->mlx)
		return (1);
	if (info->width * 50 > 2560 || info->height * 50 > 1440)
		return (1);
	info->window = mlx_new_window(info->mlx, width_w, height_w, "so_long");
	if (!info->window)
	{
		return (free(info->mlx), 1);
	}
	if (render_all_map(info) == 1)
	{
		return (1);
	}
	mlx_key_hook(info->window, handle_keys, info);
	mlx_hook(info->window, 17, 0, destroy_window, info);
	mlx_loop(info->mlx);
	return (0);
}
