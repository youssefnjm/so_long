/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_window3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 12:52:23 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 12:52:23 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_info *info, void *pic, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->window, pic, x * 50, y * 50);
}

void	*put_xmp(t_info *info, char *src)
{
	void	*pic;
	int		w;
	int		h;

	pic = mlx_xpm_file_to_image(info->mlx, src, &h, &w);
	if (!pic)
		return (NULL);
	return (pic);
}

int	init_image_part1(t_info *info)
{
	info->door_open = put_xmp(info, "./textures/door_open.xpm");
	if (!info->door_open)
		return (1);
	info->door_close = put_xmp(info, "./textures/door_close.xpm");
	if (!info->door_close)
		return (1);
	info->block = put_xmp(info, "./textures/block.xpm");
	if (!info->block)
		return (1);
	info->floor = put_xmp(info, "./textures/floor.xpm");
	if (!info->floor)
		return (1);
	info->player = put_xmp(info, "./textures/player.xpm");
	if (!info->player)
		return (1);
	info->snowman = put_xmp(info, "./textures/snowman.xpm");
	if (!info->snowman)
		return (1);
	return (0);
}

int	init_image_part2(t_info *info)
{
	info->collectible[0] = put_xmp(info, "./textures/collectible1.xpm");
	if (!info->collectible[0])
		return (1);
	info->collectible[1] = put_xmp(info, "./textures/collectible2.xpm");
	if (!info->collectible[1])
		return (1);
	info->collectible[2] = put_xmp(info, "./textures/collectible3.xpm");
	if (!info->collectible[2])
		return (1);
	info->collectible[3] = put_xmp(info, "./textures/collectible4.xpm");
	if (!info->collectible[3])
		return (1);
	info->collectible[4] = put_xmp(info, "./textures/collectible5.xpm");
	if (!info->collectible[4])
		return (1);
	info->collectible[5] = put_xmp(info, "./textures/collectible6.xpm");
	if (!info->collectible[5])
		return (1);
	return (0);
}

int	init_images(t_info *info)
{
	if (init_image_part1(info) == 1)
		return (1);
	if (init_image_part2(info) == 1)
		return (1);
	info->wall_top = put_xmp(info, "./textures/wall_top.xpm");
	if (!info->wall_top)
		return (1);
	info->wall_side = put_xmp(info, "./textures/wall_side.xpm");
	if (!info->wall_side)
		return (1);
	info->wall_top_right = put_xmp(info, "./textures/wall_top_right.xpm");
	if (!info->wall_top_right)
		return (1);
	info->wall_top_left = put_xmp(info, "./textures/wall_top_left.xpm");
	if (!info->wall_top_left)
		return (1);
	info->wall_bottom_right = put_xmp(info, "./textures/wall_bottom_right.xpm");
	if (!info->wall_bottom_right)
		return (1);
	info->wall_bottom_left = put_xmp(info, "./textures/wall_bottom_left.xpm");
	if (!info->wall_bottom_left)
		return (1);
	return (0);
}
