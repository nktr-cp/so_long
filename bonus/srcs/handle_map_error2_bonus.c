/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_error2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:42:34 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 19:21:00 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_filename(t_gameinfo *info, char *filename)
{
	int	i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (ft_strcmp(filename + i, ".ber"))
		exit_with_message(info, FILENAME, true);
}

static void	dfs(int x, int y, bool **table, t_gameinfo *info)
{
	table[x][y] = true;
	if (x + 1 < info->height && !table[x + 1][y] && info->map[x + 1][y] != '1')
		dfs(x + 1, y, table, info);
	if (y + 1 < info->width && !table[x][y + 1] && info->map[x][y + 1] != '1')
		dfs(x, y + 1, table, info);
	if (x - 1 >= 0 && !table[x - 1][y] && info->map[x - 1][y] != '1')
		dfs(x - 1, y, table, info);
	if (y - 1 >= 0 && !table[x][y - 1] && info->map[x][y - 1] != '1')
		dfs(x, y - 1, table, info);
}

void	check_reachable(t_gameinfo *info)
{
	int		i;
	int		j;
	bool	**table;

	table = prepare_table(info->height, info->width);
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
			if (info->map[i][j] == 'P')
				dfs(i, j, table, info);
	}
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
			if ((info->map[i][j] == 'E' || info->map[i][j] == 'C')
				&& !table[i][j])
				exit_with_message(info, UNREACHABLE, true);
	}
	free_table(table, info->height);
}
