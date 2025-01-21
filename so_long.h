/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-03 10:43:07 by ynoujoum          #+#    #+#             */
/*   Updated: 2025-01-03 10:43:07 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct info
{
	int		fd;
	char	**map;
	char	**map_cpy;
	int		width;
	int		height;
	int		person;
	int		coin;
	int		exit;
	int		xp;
	int		yp;
	int		xdoor;
	int		ydoor;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*wall_top;
	void	*wall_side;
	void	*wall_top_right;
	void	*wall_top_left;
	void	*wall_bottom_right;
	void	*wall_bottom_left;
	void	*block;
	void	*floor;
	void	*collectible;
	void	*door_close;
	void	*door_open;
	void	*player;
	int		move_count;
}	t_info;

void	free_memory(char **map, int i);
char	**ft_safe_malloc_map(t_info *info);

int		check_new_line(char	*str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strcpy(char	*dest, char	*src);
char	*get_next_line(int fd);

char	**ft_split(char *s, char c);
void	ft_putnbr(int n);

int		check_map(char **map, t_info *info);
int		check_map_paths(char **map, t_info *info);

int		render_game(t_info *info);
int		init_images(t_info *info);
int		render_all_map(t_info *info);
void	render_walls(t_info *info);
void	render_floor(t_info *info);
void	render_charachters(t_info *info);
int		handle_keys(int keycode, void *info);
void	render_door(t_info *info);
void	*put_xmp(t_info *info, char *src);
void	put_img(t_info *info, void *pic, int x, int y);
int		destroy_window(void *info);

#endif