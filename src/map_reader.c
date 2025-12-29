/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:10:00 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/29 01:06:16 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	check_line(t_game *d)
{
	size_t	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1'
			&& d->big_line[i] != '0' && d->big_line[i] != 'P'
			&& d->big_line[i] != '\n')
			ft_error(d, 8);
		if (d->big_line[i] == 'C')
			d->consum++;
		if (d->big_line[i] == 'E')
			d->ex++;
		if (d->big_line[i] == '1')
			d->wall++;
		if (d->big_line[i] == '0')
			d->back++;
		if (d->big_line[i] == 'P')
		{
			d->player++;
			d->player_pos = i;
		}
		i++;
	}
	if (d->consum < 1 || d->ex < 1 || d->wall < 1
		|| d->player != 1)
		ft_error(d, 5);
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
			ft_error(d, 2);
	}
	i = d->width_l;
	while (i < d->map_len)
	{
		if (d->big_line[i] == '1')
			i = i + d->width_l;
		else
			ft_error(d, 1);
	}
}

void	check_n_s(t_game *d)
{
	size_t	i;
	size_t	last;
	size_t	j;

	i = 0;
	j = 0;
	last = d->map_len - d->width_l;
	while (i < d->width_l)
	{
		if (d->big_line[i] != '1' && d->big_line[i] != '\n')
			ft_error(d, 3);
		i++;
	}
	while (last < d->map_len)
	{
		if (d->big_line[last] != '1' && d->big_line[last] != '\n')
			ft_error(d, 4);
		last++;
	}
}

void	map_reader(t_game *d)
{
	int	fd;
	char	*line;
	char	*tmp;

	fd = open(d->map, O_RDONLY);
	if (fd < 0)
		ft_error(d, 0);
	d->big_line = NULL;
	d->height_l = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error(d, 9);
	d->width_l = ft_strlen(line);
	if (d->width_l == 0 || line[d->width_l - 1] != '\n')
		ft_error(d, 7);
	d->big_line = ft_strdup(line);
	free(line);
	d->height_l = 1;
	while ((line = get_next_line(fd)))
	{
		d->height_l++;
		if (ft_strlen(line) != d->width_l)
			ft_error(d, 7);
		tmp = d->big_line;
		d->big_line = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	close(fd);
	if (d->height_l < 3)
		ft_error(d, 9);
	d->map_len = ft_strlen(d->big_line);
	check_n_s(d);
	check_e_w(d);
	check_line(d);
	check_valid_path(d);
}
