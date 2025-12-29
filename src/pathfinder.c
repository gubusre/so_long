/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:57:19 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/29 01:13:03 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

char	*duplicate_map(t_game *d)
{
	char	*copy;

	copy = ft_strdup(d->big_line);
	if (!copy)
		ft_error(d, 0);
	return (copy);
}

void	flood_fill(char *map, int width, int pos, int *collected, int *exit_reached)
{
	if (map[pos] == '1' || map[pos] == 'V')
		return ;
	if (map[pos] == 'C')
		(*collected)++;
	if (map[pos] == 'E')
		*exit_reached = 1;
	map[pos] = 'V';
	if (pos >= width && map[pos - width] != 'V')
		flood_fill(map, width, pos - width, collected, exit_reached);
	if (map[pos + width] != '\0' && map[pos + width] != '\n' && map[pos + width] != 'V')
		flood_fill(map, width, pos + width, collected, exit_reached);
	if (pos > 0 && map[pos - 1] != '\n' && map[pos - 1] != 'V')
		flood_fill(map, width, pos - 1, collected, exit_reached);
	if (map[pos + 1] != '\n' && map[pos + 1] != 'V')
		flood_fill(map, width, pos + 1, collected, exit_reached);
}

void	check_valid_path(t_game *d)
{
	char	*map_copy;
	int	collected;
	int	exit_reached;

	collected = 0;
	exit_reached = 0;
	map_copy = duplicate_map(d);
	if (!map_copy)
		ft_error(d, 0);
	flood_fill(map_copy, d->width_l, d->player_pos, &collected, &exit_reached);
	free(map_copy);
	if (collected != d->consum)
		ft_error(d, 10);
	if (!exit_reached)
		ft_error(d, 11);
}
