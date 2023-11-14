/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:35:10 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 19:12:49 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_steps_stdout(t_gameinfo *info)
{
	char	*steps;

	steps = ft_itoa(info->steps);
	if (steps == NULL)
		exit_with_message(info, ALLOC_FAIL, true);
	ft_printf("\r\x1b[33;01mSteps: ");
	ft_putendl_fd(steps, STDOUT_FILENO);
	free(steps);
}

void	print_steps(t_gameinfo *info)
{
	char	*steps;

	steps = ft_itoa(info->steps);
	if (steps == NULL)
		exit_with_message(info, ALLOC_FAIL, true);
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
			"textures/player_up.png", &img_width, &img_height);
	graphics->player_down = mlx_png_file_to_image(graphics->mlx,
			"textures/player_down.png", &img_width, &img_height);
	graphics->player_right = mlx_png_file_to_image(graphics->mlx,
			"textures/player_right.png", &img_width, &img_height);
	graphics->player_left = mlx_png_file_to_image(graphics->mlx,
			"textures/player_left.png", &img_width, &img_height);
	graphics->enemy = mlx_png_file_to_image(graphics->mlx,
			"textures/enemy1.png", &img_width, &img_height);
	graphics->enemy1 = mlx_png_file_to_image(graphics->mlx,
			"textures/enemy1.png", &img_width, &img_height);
	graphics->enemy2 = mlx_png_file_to_image(graphics->mlx,
			"textures/enemy2.png", &img_width, &img_height);
	graphics->wall = mlx_png_file_to_image(graphics->mlx,
			"textures/wall.png", &img_width, &img_height);
	graphics->floor = mlx_png_file_to_image(graphics->mlx,
			"textures/floor.png", &img_width, &img_height);
	graphics->exit = mlx_png_file_to_image(graphics->mlx,
			"textures/exit.png", &img_width, &img_height);
	graphics->collec = mlx_png_file_to_image(graphics->mlx,
			"textures/item.png", &img_width, &img_height);
}
