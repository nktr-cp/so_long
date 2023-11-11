/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:11 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 14:27:01 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_message(t_graphics *graphics, char *out, bool err)
{
	int	i;

	i = 0;
	if (err)
		write (STDERR_FILENO, "Error\n", 6);
	while (out[i])
		write (STDERR_FILENO, out + i++, 1);
	if (graphics->mlx)
		mlx_destroy_window(graphics->mlx, graphics->mlx_win);
	exit(EXIT_FAILURE);
}

void	init_members(t_gameinfo *info)
{
	info->map = NULL;
	info->height = 0;
	info->width = 0;
	info->collect_rest = 0;
	info->steps = 0;
}

bool	**prepare_table(int height, int width)
{
	bool	**table;
	int		i;

	table = (bool **)ft_calloc(height, sizeof(bool *));
	i = 0;
	while (i < height)
		table[i++] = (bool *)ft_calloc(width, sizeof(bool));
	return (table);
}

void	free_table(bool **table, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(table[i++]);
	free(table);
}
