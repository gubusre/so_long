/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:47:00 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/07 00:06:38 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"
#include "stdio.h"

void	init_img(t_game *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->x = (d->width_l - 1) * 50;
	d->y = (d->map_len / d->width_l) * 50;
	d->bush = mlx_xpm_file_to_image(d->mlx, "textures/bush.xpm", &w, &h);
	d->fond = mlx_xpm_file_to_image(d->mlx, "textures/fond.xpm", &w, &h);
	d->poke = mlx_xpm_file_to_image(d->mlx, "textures/poke.xpm", &w, &h);
	d->npcstart = mlx_xpm_file_to_image(d->mlx, "textures/enemymv.xpm", &w, &h);
	d->npc = mlx_xpm_file_to_image(d->mlx, "textures/npc.xpm", &w, &h);
	d->npcmv = mlx_xpm_file_to_image(d->mlx, "textures/npcmv.xpm", &w, &h);
	d->npcleft = mlx_xpm_file_to_image(d->mlx, "textures/npcl.xpm", &w, &h);
	d->npclmv = mlx_xpm_file_to_image(d->mlx, "textures/npclmv.xpm", &w, &h);
	d->npcright = mlx_xpm_file_to_image(d->mlx, "textures/npcr.xpm", &w, &h);
	d->npcrmv = mlx_xpm_file_to_image(d->mlx, "textures/npcrmv.xpm", &w, &h);
	d->npcback = mlx_xpm_file_to_image(d->mlx, "textures/npcback.xpm", &w, &h);
	d->npcbmv = mlx_xpm_file_to_image(d->mlx, "textures/npcbackmv.xpm", &w, &h);
	d->imgexit = mlx_xpm_file_to_image(d->mlx, "textures/imgexit.xpm", &w, &h);
	if (!d->bush || !d->fond || !d->poke || !d->npc || !d->npcmv || !d->npcleft
		|| !d->npclmv || !d->npcright || !d->npcrmv || !d->npcback
		|| !d->npcbmv || !d->npcstart || !d->imgexit)
	{
		if (d->npcstart)
			mlx_destroy_image(d->mlx, d->npcstart);
		ft_error(d, 12);
	}
}

void	check_map_extension(t_game *d)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (d->map[i])
	{
		if (d->map[i] == '/')
			j = i;
		i++;
	}
	if ((i - j) > 5 && (d->map[j + 1] != '.' && (i - j != 7))
		&& d->map[i - 4] == '.' && d->map[i - 3] == 'b'
		&& d->map[i - 2] == 'e' && d->map[i - 1] == 'r')
		return ;
	else
		ft_error(d, 1);
}

void	data_initer(t_game *d)
{
	d->big_line = NULL;
	d->start = 0;
	d->moves = 0;
	d->height_l = 1;
	map_reader(d);
	d->mlx = mlx_init();
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	map_printer(d);
	mlx_destroy_image(d->mlx, d->npcstart);
	d->npcstart = NULL;
	d->moves_p = "0";
	write(1, d->moves_p, ft_strlen(d->moves_p));
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	t_game	*d;

	d = ft_calloc(1, sizeof(t_game));
	if (!d)
		return (0);
	if (argc != 2)
		ft_error(d, 0);
	d->map = argv[1];
	check_map_extension(d);
	data_initer(d);
	mlx_hook(d->win, 2, 1L << 0, key_press, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	return (0);
}
