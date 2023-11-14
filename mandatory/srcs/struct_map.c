/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:50:21 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/11 19:30:35 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_add_new_line(t_gameinfo *info, char *newline)
{
	int		i;
	char	**map_tmp;

	i = 0;
	info->height++;
	map_tmp = (char **)malloc(sizeof(char *) * (info->height + 1));
	map_tmp[info->height] = NULL;
	while (i < info->height - 1)
	{
		map_tmp[i] = info->map[i];
		i++;
	}
	map_tmp[i] = newline;
	free(info->map);
	info->map = map_tmp;
}

void	struct_map(t_gameinfo *info, char *mapname)
{
	int		fd;
	char	*line;

	check_filename(info, mapname);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit_with_message(info, CANT_OPEN, true);
	info->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_add_new_line(info, line);
	}
	check_map(info);
	close(fd);
}
