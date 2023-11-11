/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:25:42 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 14:36:16 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	put_image_player(t_gameinfo *info, int keycode, int x, int y)
{
	if (keycode == -1)
		keycode = info->graphics.player_state;
	info->graphics.player_state = keycode;
	if (keycode == UP)
		put_image(info, info->graphics.player_up, x, y);
	if (keycode == DOWN)
		put_image(info, info->graphics.player_down, x, y);
	if (keycode == RIGHT)
		put_image(info, info->graphics.player_right, x, y);
	if (keycode == LEFT)
		put_image(info, info->graphics.player_left, x, y);
}

void	struct_graphics(t_gameinfo *info, int keycode)
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
				put_image_player(info, keycode, i, j);
			if (info->map[i][j] == 'X')
				put_image(info, info->graphics.enemy, i, j);
		}
	}
	print_steps(info);
}

static bool	choose_move(t_gameinfo *info, int x, int y)
{
	if (info->map[x][y] == '1')
		return (false);
	if (info->map[x][y] == 'E')
	{
		if (info->collect_rest)
			return (false);
		exit_with_message(&info->graphics, WIN, false);
	}
	if (info->map[x][y] == '0' || info->map[x][y] == 'C')
	{
		info->map[x][y] = 'P';
		info->steps++;
	}
	if (info->map[x][y] == 'X')
		exit_with_message(&info->graphics, LOSE, false);
	print_steps_stdout(info);
	return (true);
}

bool	do_move(t_gameinfo *vars, int x_diff, int y_diff)
{
	int	x;
	int	y;

	x = vars->graphics.player_x + x_diff;
	y = vars->graphics.player_y + y_diff;
	if (choose_move(vars, x, y))
		vars->map[x - x_diff][y - y_diff] = '0';
	return (true);
}
