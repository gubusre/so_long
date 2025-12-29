/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:47:00 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/21 21:37:07 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	init_img(t_game *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->x = (d->width_l - 1) * 50;
	d->y = (d->map_len / d->width_l + 1) * 50; 
	d->bush = mlx_xpm_file_to_image(d->mlx, "img/bush.xpm", &w, &h);
	d->fond = mlx_xpm_file_to_image(d->mlx, "img/fond.xpm", &w, &h);
	d->poke = mlx_xpm_file_to_image(d->mlx, "img/poke.xpm", &w, &h);
	d->npcstart = mlx_xpm_file_to_image(d->mlx, "img/npc.xpm", &w, &h);
	d->npc = mlx_xpm_file_to_image(d->mlx, "img/npc.xpm", &w, &h);
	d->npcmv = mlx_xpm_file_to_image(d->mlx, "img/npcmv.xpm", &w, &h);
	d->npcleft = mlx_xpm_file_to_image(d->mlx, "img/npcleft.xpm", &w, &h);
	d->npclmv = mlx_xpm_file_to_image(d->mlx, "img/npcleftmv.xpm", &w, &h);
	d->npcright = mlx_xpm_file_to_image(d->mlx, "img/npcright.xpm", &w, &h);
	d->npcrmv = mlx_xpm_file_to_image(d->mlx, "img/npcrightmv.xpm", &w, &h);
	d->npcback = mlx_xpm_file_to_image(d->mlx, "img/npcback.xpm", &w, &h);
	d->npcbmv = mlx_xpm_file_to_image(d->mlx, "img/npcbackmv.xpm", &w, &h);
	d->imgexit = mlx_xpm_file_to_image(d->mlx, "img/imgexit.xpm", &w, &h);
}

void	check_map_extension(t_game *d)
{
	int	i;

	i = ft_strlen(d->map);
	if (i > 2 && d->map[i - 4] == '.' && d->map[i - 3] == 'b'
		&& d->map[i - 2] == 'e' && d->map[i - 1] == 'r')
		return ;
	else
		ft_error(d, 6);
}

void	data_initer(t_game *d)
{
	d->moves = 0;
	check_map_extension(d);
	map_reader(d);
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "poxemon");
	map_printer(d);
}

int	main(int argc, char *argv[])
{
	t_game	*d;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	d = ft_calloc(1, sizeof(t_game));
	if (!d)
		return (0);
	d->mlx = mlx_init();
	d->map = argv[1];
	data_initer(d);
	mlx_key_hook(d->win, key_press, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}
