/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:35:10 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 15:52:40 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_steps_stdout(t_gameinfo *info)
{
	char	*steps;

	steps = ft_itoa(info->steps);
	if (steps == NULL)
		exit_with_message(&info->graphics, ALLOC_FAIL, true);
	ft_printf("\r\x1b[33;01mSteps: ");
	ft_putendl_fd(steps, STDOUT_FILENO);
	free(steps);
}

void	print_steps(t_gameinfo *info)
{
	char	*steps;

	steps = ft_itoa(info->steps);
	if (steps == NULL)
		exit_with_message(&info->graphics, ALLOC_FAIL, true);
	mlx_string_put(info->graphics.mlx,
		info->graphics.mlx_win, 30, 30, 0xFF0000, "STEPS:");
	mlx_string_put(info->graphics.mlx,
		info->graphics.mlx_win, 95, 30, 0xFFF000, steps);
	free(steps);
}

void	set_images(t_graphics *graphics)
{
	int	img_width;
	int	img_height;

	graphics->player_up = mlx_png_file_to_image(graphics->mlx,
			"images/player_up.png", &img_width, &img_height);
	graphics->player_down = mlx_png_file_to_image(graphics->mlx,
			"images/player_down.png", &img_width, &img_height);
	graphics->player_right = mlx_png_file_to_image(graphics->mlx,
			"images/player_right.png", &img_width, &img_height);
	graphics->player_left = mlx_png_file_to_image(graphics->mlx,
			"images/player_left.png", &img_width, &img_height);
	graphics->enemy = mlx_png_file_to_image(graphics->mlx,
			"images/enemy1.png", &img_width, &img_height);
	graphics->enemy1 = mlx_png_file_to_image(graphics->mlx,
			"images/enemy1.png", &img_width, &img_height);
	graphics->enemy2 = mlx_png_file_to_image(graphics->mlx,
			"images/enemy2.png", &img_width, &img_height);
	graphics->wall = mlx_png_file_to_image(graphics->mlx,
			"images/wall.png", &img_width, &img_height);
	graphics->floor = mlx_png_file_to_image(graphics->mlx,
			"images/floor.png", &img_width, &img_height);
	graphics->exit = mlx_png_file_to_image(graphics->mlx,
			"images/exit.png", &img_width, &img_height);
	graphics->collec = mlx_png_file_to_image(graphics->mlx,
			"images/item.png", &img_width, &img_height);
}
