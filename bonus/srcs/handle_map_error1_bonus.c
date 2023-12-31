/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_error1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:42:22 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/14 18:25:42 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	is_rectangular(t_gameinfo *info)
{
	size_t	w;
	size_t	len;
	int		i;

	w = 0;
	while (info->map[0][w] && info->map[0][w] != '\n')
		w++;
	i = 1;
	while (info->map[i])
	{
		len = 0;
		while (info->map[i][len] && info->map[i][len] != '\n')
			len++;
		if (len != w)
			exit_with_message(info, SHAPE, true);
		i++;
	}
	info->width = w;
}

static void	check_components(t_gameinfo *info, t_components *comps,
		int x, int y)
{
	if (info->map[x][y] != '0' && info->map[x][y] != '1' &&
		info->map[x][y] != 'C' && info->map[x][y] != 'X' &&
		info->map[x][y] != 'E' && info->map[x][y] != 'P')
		exit_with_message(info, INVALID, true);
	if (info->map[x][y] == 'X')
		info->graphics.num_enemy++;
	if (info->map[x][y] == 'C')
		comps->collective_cmp++;
	if (info->map[x][y] == 'E')
		comps->exit_cmp++;
	if (info->map[x][y] == 'P')
		comps->start_cmp++;
}

static void	has_appropriate_number_of_components(t_gameinfo *info)
{
	int				i;
	int				j;
	t_components	comps;

	comps.collective_cmp = 0;
	comps.exit_cmp = 0;
	comps.start_cmp = 0;
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j] != '\0' && info->map[i][j] != '\n')
			check_components(info, &comps, i, j++);
		i++;
	}
	if (!comps.collective_cmp
		|| comps.exit_cmp != 1 || comps.start_cmp != 1)
		exit_with_message(info, LACK, true);
}

static void	surrounded_by_walls(t_gameinfo *info)
{
	int	i;

	i = 0;
	while (info->map[i] && info->map[i][0] == '1')
		i++;
	if (i != info->height)
		exit_with_message(info, INCOMPLETE, true);
	i = 0;
	while (info->map[i] && info->map[i][info->width - 1] == '1')
		i++;
	if (i != info->height)
		exit_with_message(info, INCOMPLETE, true);
	i = 0;
	while (info->map[0][i] == '1')
		i++;
	if (i != info->width)
		exit_with_message(info, INCOMPLETE, true);
	i = 0;
	while (info->map[info->height - 1][i] == '1')
		i++;
	if (i != info->width)
		exit_with_message(info, INCOMPLETE, true);
}

void	check_map(t_gameinfo *info)
{
	if (info->height > 50)
		exit_with_message(info, TOOLARGE, true);
	if (info->map == NULL)
		exit_with_message(info, LACK, true);
	is_rectangular(info);
	has_appropriate_number_of_components(info);
	surrounded_by_walls(info);
	check_reachable(info);
}
