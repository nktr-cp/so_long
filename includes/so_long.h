/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:16:12 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/04 20:42:08 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <mlx.h>

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

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
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collec;
}	t_graphics;

typedef struct s_gameinfo
{
	char		**map;
	int			height;
	int			width;
	t_graphics	graphics;
}	t_gameinfo;

void	struct_map(t_gameinfo *info, char *mapname);

void	exit_with_message(char *out);
void	init_members(t_gameinfo *info);

void	check_reachable(t_gameinfo *info);
void	check_filename(char *filename);

void	check_map(t_gameinfo *info);
#endif