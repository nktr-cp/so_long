/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:56:11 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/04 16:51:50 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_members(t_gameinfo *info)
{
	info->map = NULL;
	info->height = 0;
}

void	map_add_new_line(t_gameinfo *info, char *newline)
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

	check_filename(mapname);
	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		exit_with_message("Unable to open a given file.\n");
	info->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_add_new_line(info, line);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_gameinfo	info;

	if (argc != 2)
		exit_with_message("The number of arguments is invalid\n");
	init_members(&info);
	struct_map(&info, argv[1]);
	check_map(&info);
}
