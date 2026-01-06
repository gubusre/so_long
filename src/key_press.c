/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:15:01 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 23:33:08 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	move_w(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - d->width_l] != '1'
		&& check_exit(d, d->big_line[i - d->width_l]) == 0)
	{
		d->moves++;
		if (d->big_line[i - d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width_l] = 'P';
	}
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
	map_printer(d);
}

void	move_s(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + d->width_l] != '1'
		&& check_exit(d, d->big_line[i + d->width_l]) == 0)
	{
		d->moves++;
		if (d->big_line[i + d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + d->width_l] = 'P';
	}
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
	map_printer(d);
}

void	move_a(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1'
		&& check_exit(d, d->big_line[i - 1]) == 0)
	{
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - 1] = 'P';
	}
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
	map_printer(d);
}

void	move_d(t_game *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + 1] != '1'
		&& check_exit(d, d->big_line[i + 1]) == 0)
	{
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + 1] = 'P';
	}
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
	map_printer(d);
}

int	key_press(int key, t_game *d)
{
	int		old_moves;

	old_moves = d->moves;
	if (key == 53 || key == 65307)
		ft_free(d);
	if (key == 123 || key == 65361 || key == 97 || key == 65)
		move_a(d);
	if (key == 125 || key == 65364 || key == 115 || key == 83)
		move_s(d);
	if (key == 124 || key == 65363 || key == 100 || key == 68)
		move_d(d);
	if (key == 126 || key == 65362 || key == 119 || key == 87)
		move_w(d);
	d->moves_p = ft_itoa(d->moves);
	if (d->moves > old_moves || (d->start == 0 && d->moves > 0))
	{
		d->start++;
		write(1, d->moves_p, ft_strlen(d->moves_p));
		write(1, "\n", 1);
	}
	if (d->moves_p)
		free(d->moves_p);
	return (0);
}
