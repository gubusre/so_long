/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:52:22 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/29 01:16:12 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

int	check_exit(t_game *d, char letter)
{
	if (letter == 'E')
	{
		if (d->consum == 0)
		{
			write(1, "The End 🥳🏆\n", 17);
			ft_free(d);
		}
		else
			write(1, "You forgot something!\n", 22);
		return (1);
	}
	return (0);
}
