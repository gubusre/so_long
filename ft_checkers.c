/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:52:22 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 20:05:34 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	check_exit(t_game *d, char map_pos)
{
	if (map_pos == 'E')
	{
		if (d->consum == 0)
		{
			d->moves = d->moves + 1;
			d->moves_p = ft_itoa(d->moves);
			write(1, d->moves_p, ft_strlen(d->moves_p));
			write(1, "\n", 1);
			write(1, "The End\n", 8);
			free(d->moves_p);
			ft_free(d);
		}
		else
			write(1, "You forgot something!\n", 22);
		return (1);
	}
	return (0);
}

void	check_line(t_game *d)
{
	size_t	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1' && d->big_line[i] != '0'
			&& d->big_line[i] != 'P' && d->big_line[i] != '\n')
			ft_error(d, 9);
		if (d->big_line[i] == 'C')
			d->consum++;
		if (d->big_line[i] == 'E')
			d->exit++;
		if (d->big_line[i] == '1')
			d->wall++;
		if (d->big_line[i] == '0')
			d->back++;
		if (d->big_line[i] == 'P')
			d->player++;
		i++;
	}
	if (d->consum < 1 || d->exit != 1 || d->wall < 1
		|| d->player != 1)
		ft_error(d, 8);
}

void	check_e_w(t_game *d)
{
	size_t	i;

	i = d->width_l - 2;
	while (i < d->map_len)
	{
		if (d->big_line[i] == '1')
			i = i + d->width_l;
		else
			ft_error(d, 6);
	}
	i = d->width_l;
	while (i < d->map_len)
	{
		if (d->big_line[i] == '1')
			i = i + d->width_l;
		else
			ft_error(d, 7);
	}
}

void	check_n_s(t_game *d)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = d->map_len - d->width_l;
	while (i < d->width_l)
	{
		if (d->big_line[i] != '1' && d->big_line[i] != '\n')
			ft_error(d, 4);
		i++;
	}
	while (last < d->map_len)
	{
		if (d->big_line[last] != '1' && d->big_line[last] != '\n')
			ft_error(d, 5);
		last++;
	}
}
