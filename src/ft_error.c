/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:57:49 by gubusque          #+#    #+#             */
/*   Updated: 2026/01/06 22:57:50 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	ft_error2(t_game *d, int n)
{
	int	err;

	err = 0;
	if (n == 8)
	{
		if (d->player != 1)
			write(1, "Map must have -> ONE player\n", 28);
		if (d->exit != 1)
			write(1, "Map must have -> ONE exit\n", 26);
		if (d->consum < 1)
			write(1, "Map must have -> ONE consumable, atleast\n", 41);
	}
	if (n == 9)
		write(1, "Wrong characters on map\n", 24);
	if (n == 10)
		write(1, "Player can't reach Consumable\n", 30);
	if (n == 11)
		write(1, "Palyer can't reach Exit\n", 24);
	if (n == 12)
		write (1, ".xpm file corrupt or not found\n", 31);
}

void	ft_error(t_game *d, int n)
{
	write(1, "Error\n", 6);
	if (n > 7)
		ft_error2(d, n);
	if (n == 0)
		write(1, "Invalid quantity of arguments\n", 30);
	if (n == 1)
		write(1, "Wrong extension\n", 16);
	if (n == 2)
		write(1, "Wrong map size\n", 15);
	if (n == 3)
		write(1, "Wrong map composition\n", 22);
	if (n == 4)
		write(1, "North wall not closed\n", 22);
	if (n == 5)
		write(1, "South wall not closed\n", 22);
	if (n == 6)
		write(1, "East wall not closed\n", 21);
	if (n == 7)
		write(1, "West wall not closed\n", 21);
	ft_free(d);
	exit(1);
}
