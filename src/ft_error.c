/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:57:49 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/21 22:37:34 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	ft_error2(t_game *d, int n)
{
	d->moves++;
	d->moves--;
	if (n == 8)
	       write(1, "Wrong characters on map\n", 24);
	if (n == 9)
	       write(1, "Wrong map size\n", 15);
	if (n == 10)
		write(1, "Player can't Reach Consumable\n", 30);
	if (n == 11)
		write(1, "Palyer can't Reach Exit\n", 24);

}

void	ft_error(t_game *d, int n)
{
	write(1, "error\n", 6);
	if (n > 7)
		ft_error2(d, n);
	if (n == 0)
		write(1, "Invalid quantity of argumens\n", 29);
	if (n == 1)
		write(1, "No wall on firsts of line\n", 28);
	if (n == 2)
		write(1, "No wall on least of line\n", 27);
	if (n == 3)
		write(1, "No wall on first line\n", 22);
	if (n == 4)
		write(1, "No wall on last line\n", 21);
	if (n == 5)
	{
		if (d->consum < 1)
			write(1, "Map must have atleast-> ONE consumables\n", 40);
		if (d->player != 1)
			write(1, "Map must have only   -> ONE player\n", 35);
		if (d->ex < 1)
			write(1, "Map must have atleast-> ONE exit\n", 37);
	}	
	if (n == 6)
		write(1, "Wrong extension\n", 16);
	if (n == 7)
	       write (1, "Wrong map composition\n", 22);
	ft_free(d);
}
