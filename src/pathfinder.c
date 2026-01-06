/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 00:57:19 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 20:14:35 by gubusque         ###   ########.fr       */
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

void	path_finder(t_path *p)
{
	int	pos;

	if (p->map[p->pos] == 'E')
		p->exit = 1;
	if (p->map[p->pos] == '1' || p->map[p->pos] == 'V' || p->map[p->pos] == 'E')
		return ;
	if (p->map[p->pos] == 'C')
		p->col++;
	p->map[p->pos] = 'V';
	pos = p->pos;
	p->pos = pos - p->width;
	if (pos >= p->width && p->map[pos - p->width] != 'V')
		path_finder(p);
	p->pos = pos + p->width;
	if (p->map[pos + p->width] != '\0' && p->map[pos + p->width] != '\n'
		&& p->map[pos + p->width] != 'V')
		path_finder(p);
	p->pos = pos - 1;
	if (pos > 0 && p->map[pos - 1] != '\n' && p->map[pos - 1] != 'V')
		path_finder(p);
	p->pos = pos + 1;
	if (p->map[pos + 1] != '\n' && p->map[pos + 1] != 'V')
		path_finder(p);
}

int	position_finder(t_path *p)
{
	int	i;

	i = 0;
	while (p->map[i])
	{
		if (p->map[i] == 'P')
			return (i);
		i++;
	}
	return (0);
}

void	check_valid_path(t_game *d)
{
	t_path	*p;
	int		out;
	int		collected;

	p = ft_calloc(1, sizeof(t_path));
	if (!p)
		exit(0);
	p->col = 0;
	p->exit = 0;
	p->width = d->width_l;
	p->map = duplicate_map(d);
	if (!p->map)
		ft_error(d, 0);
	p->pos = position_finder(p);
	path_finder(p);
	collected = p->col;
	out = p->exit;
	free(p->map);
	free(p);
	if (collected != d->consum)
		ft_error(d, 10);
	if (!out)
		ft_error(d, 11);
}
