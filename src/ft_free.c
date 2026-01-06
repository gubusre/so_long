/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:56:25 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 23:52:32 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

static void	destroy_images(t_game *d)
{
	if (d->bush)
		mlx_destroy_image(d->mlx, d->bush);
	if (d->fond)
		mlx_destroy_image(d->mlx, d->fond);
	if (d->poke)
		mlx_destroy_image(d->mlx, d->poke);
	if (d->npc)
		mlx_destroy_image(d->mlx, d->npc);
	if (d->npcmv)
		mlx_destroy_image(d->mlx, d->npcmv);
	if (d->npcleft)
		mlx_destroy_image(d->mlx, d->npcleft);
	if (d->npclmv)
		mlx_destroy_image(d->mlx, d->npclmv);
	if (d->npcright)
		mlx_destroy_image(d->mlx, d->npcright);
	if (d->npcrmv)
		mlx_destroy_image(d->mlx, d->npcrmv);
	if (d->npcback)
		mlx_destroy_image(d->mlx, d->npcback);
	if (d->npcbmv)
		mlx_destroy_image(d->mlx, d->npcbmv);
	if (d->imgexit)
		mlx_destroy_image(d->mlx, d->imgexit);
}

int	ft_free(t_game *d)
{
	destroy_images(d);
	if (d->win)
	{
		mlx_destroy_window(d->mlx, d->win);
		d->win = NULL;
	}
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	if (d->big_line)
		free(d->big_line);
	if (d)
		free(d);
	exit (0);
}
