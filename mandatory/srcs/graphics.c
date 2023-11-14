/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:25:42 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 19:12:08 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_graphics *graphics)
{
	int	img_width;
	int	img_height;

	graphics->player = mlx_png_file_to_image(graphics->mlx,
			"textures/player_down.png", &img_width, &img_height);
	graphics->wall = mlx_png_file_to_image(graphics->mlx,
			"textures/wall.png", &img_width, &img_height);
	graphics->floor = mlx_png_file_to_image(graphics->mlx,
			"textures/floor.png", &img_width, &img_height);
	graphics->exit = mlx_png_file_to_image(graphics->mlx,
			"textures/exit.png", &img_width, &img_height);
	graphics->collec = mlx_png_file_to_image(graphics->mlx,
			"textures/item.png", &img_width, &img_height);
}

static void	put_image(t_gameinfo *info, void *image, int x, int y)
{
	mlx_put_image_to_window(info->graphics.mlx,
		info->graphics.mlx_win, image, y * PIX, x * PIX);
	if (info->map[x][y] == 'C')
		info->collect_rest++;
	if (info->map[x][y] == 'P')
	{
		info->graphics.player_x = x;
		info->graphics.player_y = y;
	}
}

void	struct_graphics(t_gameinfo *info)
{
	int	i;
	int	j;

	i = -1;
	info->collect_rest = 0;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == '0')
				put_image(info, info->graphics.floor, i, j);
			if (info->map[i][j] == '1')
				put_image(info, info->graphics.wall, i, j);
			if (info->map[i][j] == 'C')
				put_image(info, info->graphics.collec, i, j);
			if (info->map[i][j] == 'E')
				put_image(info, info->graphics.exit, i, j);
			if (info->map[i][j] == 'P')
				put_image(info, info->graphics.player, i, j);
		}
	}
}

static bool	choose_move(t_gameinfo *info, int x, int y)
{
	if (info->map[x][y] == 'E')
	{
		if (info->collect_rest)
			return (false);
		exit_with_message(info, "You win!\n", false);
	}
	if (info->map[x][y] == '0' || info->map[x][y] == 'C')
	{
		info->map[x][y] = 'P';
		info->steps++;
	}
	return (true);
}

bool	do_move(t_gameinfo *vars, int x_diff, int y_diff)
{
	int	x;
	int	y;

	x = vars->graphics.player_x + x_diff;
	y = vars->graphics.player_y + y_diff;
	if (vars->map[x][y] == '1')
		return (false);
	if (!choose_move(vars, x, y))
		return (false);
	vars->map[x - x_diff][y - y_diff] = '0';
	return (true);
}
