/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:11 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 19:16:47 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_gameinfo *vars)
{
	bool	moved;

	if (keycode == FINISH)
		exit(EXIT_SUCCESS);
	if (keycode == UP)
		moved = do_move(vars, -1, 0);
	if (keycode == DOWN)
		moved = do_move(vars, 1, 0);
	if (keycode == LEFT)
		moved = do_move(vars, 0, -1);
	if (keycode == RIGHT)
		moved = do_move(vars, 0, 1);
	if (moved)
	{
		struct_graphics(vars);
		ft_printf("steps: %d\n", vars->steps);
	}
	return (1);
}

int	close_win(t_graphics *graphics)
{
	if (graphics->mlx)
		mlx_destroy_window(graphics->mlx, graphics->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_gameinfo	info;

	ft_bzero(&info, sizeof(t_gameinfo));
	if (argc != 2)
		exit_with_message(&info, ARGS, true);
	struct_map(&info, argv[1]);
	info.graphics.mlx = mlx_init();
	info.graphics.mlx_win = mlx_new_window(info.graphics.mlx,
			info.width * PIX, info.height * PIX, "so_long");
	set_images(&info.graphics);
	struct_graphics(&info);
	mlx_key_hook(info.graphics.mlx_win, key_hook, &info);
	mlx_hook(info.graphics.mlx_win, 17, 0L, close_win, &info.graphics);
	mlx_loop(info.graphics.mlx);
}
