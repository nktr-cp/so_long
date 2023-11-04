/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:11 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/04 20:44:35 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_graphics *graphics)
{
	int	img_width;
	int	img_height;

	graphics->player = mlx_xpm_file_to_image(graphics->mlx,
		"images/player.xpm", &img_width, &img_height);
	graphics->wall = mlx_xpm_file_to_image(graphics->mlx,
		"images/wall.xpm", &img_width, &img_height);
	graphics->floor = mlx_xpm_file_to_image(graphics->mlx,
		"images/floor.xpm", &img_width, &img_height);
	graphics->exit = mlx_xpm_file_to_image(graphics->mlx,
		"images/exit.xpm", &img_width, &img_height);
	graphics->collec = mlx_xpm_file_to_image(graphics->mlx,
		"images/item.xpm", &img_width, &img_height);
}

void	struct_graphics(t_gameinfo *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == '0')
				mlx_put_image_to_window(info->graphics.mlx, info->graphics.mlx_win, info->graphics.floor, j * 40, i * 40);
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->graphics.mlx, info->graphics.mlx_win, info->graphics.wall, j * 40, i * 40);
			if (info->map[i][j] == 'C')
				mlx_put_image_to_window(info->graphics.mlx, info->graphics.mlx_win, info->graphics.collec, j * 40, i * 40);
			if (info->map[i][j] == 'E')
				mlx_put_image_to_window(info->graphics.mlx, info->graphics.mlx_win, info->graphics.exit, j * 40, i * 40);
			if (info->map[i][j] == 'P')
				mlx_put_image_to_window(info->graphics.mlx, info->graphics.mlx_win, info->graphics.player, j * 40, i * 40);
		}
	}
}

int	key_hook(int keycode, t_graphics *vars)
{
	
}

int	main(int argc, char **argv)
{
	t_gameinfo	info;

	if (argc != 2)
		exit_with_message("The number of arguments is invalid\n");
	init_members(&info);
	struct_map(&info, argv[1]);
	info.graphics.mlx = mlx_init();
	info.graphics.mlx_win = mlx_new_window(info.graphics.mlx,
		info.width * 40, info.height * 40, "so_long");
	set_images(&info.graphics);
	struct_graphics(&info);
	mlx_key_hook(info.graphics.mlx_win, key_hook, &info.graphics);
	mlx_loop(info.graphics.mlx);
}
