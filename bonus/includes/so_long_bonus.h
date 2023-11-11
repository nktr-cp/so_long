/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:31:23 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 14:37:16 by knishiok         ###   ########.fr       */
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
# include <time.h>

# define PIX 64

# define FINISH 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

# define LACK "\x1b[31;01mGiven map has insufficient number of components.\n"
# define SHAPE "\x1b[31;01mGiven map is not rectangular.\n"
# define INVALID "\x1b[31;01mGiven map contains an invalid component.\n"
# define INCOMPLETE "\x1b[31;01mGiven map is not surrounded by walls.\n"
# define FILENAME "\x1b[31;01mGiven filename does not end with .ber.\n"
# define UNREACHABLE "\x1b[31;01mUnable to reach the goal.\n"
# define CANT_OPEN "\x1b[31;01mUnable to open the given file.\n"
# define ARGS "\x1b[31;01mThe number of arguments is invalid\n"
# define ALLOC_FAIL "[31;01mMemory allocation failed.\n"
# define WIN "\x1b[32;01m✌️ You win!\n"
# define LOSE "\x1b[31;01m😭You lose...\n"

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
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collec;
	int		player_x;
	int		player_y;
	int		num_enemy;
	int		player_state;
}	t_graphics;

typedef struct s_gameinfo
{
	char		**map;
	int			height;
	int			width;
	int			collect_rest;
	int			steps;
	long long	actions;
	t_graphics	graphics;
}	t_gameinfo;

void	struct_map(t_gameinfo *info, char *mapname);

void	print_steps_stdout(t_gameinfo *info);
void	print_steps(t_gameinfo *info);
void	set_images(t_graphics *graphics);

bool	do_move(t_gameinfo *vars, int x_diff, int y_diff);
void	struct_graphics(t_gameinfo *info, int keycode);
void	set_images(t_graphics *graphics);

void	exit_with_message(t_graphics *graphics, char *out, bool err);
void	init_members(t_gameinfo *info);
bool	**prepare_table(int height, int width);
void	free_table(bool **table, int size);

void	check_reachable(t_gameinfo *info);
void	check_filename(t_gameinfo *info, char *filename);

void	check_map(t_gameinfo *info);

int		monster_hook(t_gameinfo *info);
#endif
