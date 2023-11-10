/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:31:23 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/10 20:38:59 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <mlx.h>

# define PIX 64

# define FINISH 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

# define LACK "Given map has insufficient number of components.\n"
# define SHAPE "Given map is not rectangular.\n"
# define INVALID "Given map contains an invalid component.\n"
# define INCOMPLETE "Given map is not surrounded by walls.\n"
# define FILENAME "Given filename does not end with .ber.\n"
# define UNREACHABLE "Unable to reach the goal.\n"
# define CANT_OPEN "Unable to open the given file.\n"
# define ARGS "The number of arguments is invalid\n"

typedef struct s_components
{
	int	collective_cmp;
	int	exit_cmp;
	int	start_cmp;
}	t_components;

typedef struct s_graphics
{
	void	*mlx;
	void	*mlx_win;
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*player_left;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collec;
	int		player_x;
	int		player_y;
}	t_graphics;

typedef struct s_gameinfo
{
	char		**map;
	int			height;
	int			width;
	int			collect_rest;
	int			steps;
	t_graphics	graphics;
}	t_gameinfo;

void	struct_map(t_gameinfo *info, char *mapname);

bool	do_move(t_gameinfo *vars, int x_diff, int y_diff);
void	struct_graphics(t_gameinfo *info, int keycode);
void	set_images(t_graphics *graphics);

void	exit_with_message(char *out, bool err);
void	init_members(t_gameinfo *info);
bool	**prepare_table(int height, int width);
void	free_table(bool **table, int size);

void	check_reachable(t_gameinfo *info);
void	check_filename(char *filename);

void	check_map(t_gameinfo *info);
#endif
