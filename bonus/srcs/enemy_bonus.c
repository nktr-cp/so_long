/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:46:51 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 12:42:27 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	monster_move(t_gameinfo *info, int x, int y, int dir)
{
	int	next_x;
	int	next_y;

	next_x = x;
	next_y = y;
	if (dir & 1 << 0)
		next_x--;
	if (dir & 1 << 1)
		next_x++;
	if (dir & 1 << 2)
		next_y--;
	if (dir & 1 << 3)
		next_y++;
	if (info->map[next_x][next_y] == '0')
	{
		info->map[next_x][next_y] = 'X';
		info->map[x][y] = '0';
	}
}

static void	random_move(t_gameinfo *info, int x, int y)
{
	int	dir;

	srand((unsigned int)time(NULL));
	dir = rand() % 4;
	monster_move(info, x, y, 1 << dir);
}

int	monster_hook(t_gameinfo *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == 'X' && info->actions % 100 == 0)
				random_move(info, i, j);
		}
	}
	if (info->actions % 70 == 0)
		info->graphics.enemy = info->graphics.enemy2;
	else if (info->actions % 40 == 0)
		info->graphics.enemy = info->graphics.enemy1;
	struct_graphics(info, -1);
	info->actions++;
	return (1);
}
