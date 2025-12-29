/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:15:01 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/29 01:19:53 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	move_w(t_game *d)
{
	int	i;
	char	next;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	next = d->big_line[i - d->width_l];
	if (next != '1' && !check_exit(d, next))
	{
		d->moves++;
		if (next == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width_l] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcback;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcbmv;
			d->npccontrol = 0;
		}
	}
	map_printer(d);
}

void	move_s(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + d->width_l] != '1'
		&& !check_exit(d, d->big_line[i + d->width_l]))
	{
		d->moves++;
		if (d->big_line[i + d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + d->width_l] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npc;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcmv;
			d->npccontrol = 0;
		}
	}
	map_printer(d);
}

void	move_a(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1' && !check_exit(d, d->big_line[i - 1]))
	{
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - 1] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcleft;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npclmv;
			d->npccontrol = 0;
		}
	}
	map_printer(d);
}

void	move_d(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + 1] != '1' && !check_exit(d, d->big_line[i + 1]))
	{
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + 1] = 'P';
		if (d->npccontrol == 0)
		{
			d->npcstart = d->npcright;
			d->npccontrol = 1;
		}
		else
		{
			d->npcstart = d->npcrmv;
			d->npccontrol = 0;
		}
	}
	map_printer(d);
}

int	key_press(int key, t_game *d)
{
	char	*moves_p;

	(void)d;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == 0 || key == 65361 || key == 123)
		move_a(d);
	if (key == 1 || key == 65364 || key == 125)
		move_s(d);
	if (key == 2 || key == 65363 || key == 124)
		move_d(d);
	if (key == 13 || key == 65362 || key == 126)
		move_w(d);
	moves_p = ft_itoa(d->moves);
	write(1, moves_p, ft_strlen(moves_p));
	if (moves_p)
		free(moves_p);
	write(1, "\n", 1);
	return (0);
}
