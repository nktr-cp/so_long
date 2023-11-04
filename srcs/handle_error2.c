/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:42:34 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/04 17:33:01 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_message(char *out)
{
	int	i;

	i = 0;
	write (STDERR_FILENO, "Error\n", 6);
	while (out[i])
		write (STDERR_FILENO, out + i++, 1);
	exit(EXIT_FAILURE);
}

void	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (ft_strcmp(filename + i, ".ber"))
		exit_with_message("Given filename does not end with .ber.\n");
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

	i = 0;
	table = (bool **)ft_calloc(info->height, sizeof(bool *));
	while (i < info->height)
		table[i++] = (bool *)ft_calloc(info->width, sizeof(bool));
	i = -1;
	while (++i < info->height)
	{
		j = 0;
		while (j < info->width)
			if (info->map[i][j++] == 'P')
				dfs(i, j, table, info);
	}
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
			if (info->map[i][j] == 'E' && !table[i][j])
				exit_with_message("Unable to reach a goal.\n");
	}
}
