/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:10:00 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 22:41:09 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	run_checkers(t_game *d)
{
	if (d->height_l < 3)
		ft_error(d, 2);
	d->map_len = ft_strlen(d->big_line);
	check_n_s(d);
	check_e_w(d);
	check_line(d);
	check_valid_path(d);
}

static void	read_first_line(t_game *d, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error(d, 2);
	d->width_l = ft_strlen(line);
	if (d->width_l == 0 || line[d->width_l - 1] != '\n')
	{
		free(line);
		ft_error(d, 2);
	}
	d->big_line = ft_strdup(line);
	free(line);
}

static void	read_rest_lines(t_game *d, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		d->height_l++;
		if (ft_strlen(line) != d->width_l)
		{
			free(line);
			ft_error(d, 3);
		}
		tmp = d->big_line;
		d->big_line = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
}

void	map_reader(t_game *d)
{
	int	fd;

	fd = open(d->map, O_RDONLY);
	if (fd < 0)
		ft_error(d, 0);
	read_first_line(d, fd);
	read_rest_lines(d, fd);
	close(fd);
	run_checkers(d);
}
