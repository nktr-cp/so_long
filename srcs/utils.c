/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:11 by knishiok          #+#    #+#             */
/*   Updated: 2023/11/08 06:20:39 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_message(char *out, bool err)
{
	int	i;

	i = 0;
	if(err)
		write (STDERR_FILENO, "Error\n", 6);
	while (out[i])
		write (STDERR_FILENO, out + i++, 1);
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
