/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 17:45:32 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-05 17:45:32 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	copy_map(char **map, t_info *info)
{
	int	i;
	int	j;

	info->map_cpy = ft_safe_malloc_map(info);
	if (info->map_cpy == NULL)
		return (1);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			info->map_cpy[i][j] = map[i][j];
			j++;
		}
		info->map_cpy[i][j] = '\0';
		i++;
	}
	info->map_cpy[i] = NULL;
	return (0);
}

static	int	check_characters(char **map, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!(map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P'
				|| map[i][j] == 'C' || map[i][j] == 'E'))
				return (1);
			if (map[i][j] == 'P')
				info->person++;
			else if (map[i][j] == 'C')
				info->coin++;
			else if (map[i][j] == 'E')
				info->exit++;
			j++;
		}
		i++;
	}
	if (info->exit != 1 || info->coin == 0 || info->person != 1)
		return (1);
	return (0);
}

static	int	check_len_map(char **map, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->width = 0;
	while (map[0][i++])
		info->width++;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (j != info->width)
			return (1);
		i++;
	}
	return (0);
}

static	int	check_walls(char **map, t_info *info)
{
	int	i;

	i = 0;
	if (!map || info->height < 3)
		return (1);
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' || map[info->height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		if (map[i][0] != '1' || map[i][info->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char **map, t_info *info)
{
	info->coin = 0;
	info->exit = 0;
	info->person = 0;
	info->map_cpy = NULL;
	if (check_len_map(map, info) == 1)
		return (1);
	if (check_walls(map, info) == 1)
		return (1);
	if (check_characters(map, info) == 1)
		return (1);
	if (copy_map(map, info) == 1)
		return (1);
	if (check_map_paths(map, info) == 1)
		return (1);
	return (0);
}
