/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 12:44:36 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-15 12:44:36 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**get_map(char *file_name, t_info *info)
{
	char	*map;
	char	*line;

	info->fd = open(file_name, O_RDONLY);
	if (info->fd < 0)
		return (NULL);
	info->height = 0;
	map = ft_strdup("");
	if (!map)
		return (NULL);
	line = "";
	while (1)
	{
		line = get_next_line(info->fd);
		if (!line)
			break ;
		if (line[0] == '\n' || line[0] == '\0')
			return (free(line), free(map), map = NULL, line = NULL, NULL);
		map = ft_strjoin(map, line);
		free(line);
		info->height += 1;
	}
	return (ft_split(map, '\n'));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] != '\0')
	{
		while (str[i] != '.')
			i--;
		if (i == 0 || ft_strcmp(&str[i], ".ber") != 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (write(1, "Error\n", 6), 1);
	if (check_file_name(argv[1]) == 1)
		return (write(1, "Error\n", 6), 1);
	info.map = get_map(argv[1], &info);
	close(info.fd);
	if (!info.map || !info.map[0])
		return (free_memory(info.map, info.height), write(1, "Error\n", 6), 1);
	if (check_map(info.map, &info) == 1)
	{
		free_memory(info.map, info.height);
		free_memory(info.map_cpy, info.height);
		return (write(1, "Error\n", 6), 1);
	}
	if (render_game(&info) == 1)
	{
		free_memory(info.map, info.height);
		free_memory(info.map_cpy, info.height);
		mlx_destroy_window(info.mlx, info.window);
		free(info.mlx);
		return (write(1, "Error\n", 6), 1);
	}
	return (0);
}
