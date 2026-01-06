/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:11:19 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 22:56:26 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONGLIB_H
# define LONGLIB_H

# include <mlx.h>
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct s_path
{
	char	*map;
	int		pos;
	int		width;
	int		col;
	int		exit;
}	t_path;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*bush;
	void	*fond;
	void	*poke;
	void	*npc;
	void	*npcstart;
	void	*npcmv;
	void	*npcleft;
	void	*npclmv;
	void	*npcright;
	void	*npcrmv;
	void	*npcback;
	void	*npcbmv;
	void	*imgexit;
	int		start;
	int		moves;
	int		npccontrol;
	int		x;
	int		y;
	int		consum;
	int		exit;
	int		back;
	int		wall;
	int		player;
	size_t	linecontrol;
	size_t	height_l;
	size_t	width_l;
	size_t	map_len;
	char	*big_line;
	char	*map;
	char	*moves_p;
}	t_game;

void	data_initer(t_game *d);
void	map_reader(t_game *d);
void	map_printer(t_game *d);
void	check_n_s(t_game *d);
void	check_e_w(t_game *d);
void	check_line(t_game *d);
void	check_valid_path(t_game *d);
void	ft_error(t_game *d, int n);
int		check_exit(t_game *d, char letter);
int		key_press(int key, t_game *d);
int		ft_free(t_game *d);

#endif
