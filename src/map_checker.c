/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 22:21:22 by gubusque          #+#    #+#             */
/*   Updated: 2025/12/21 22:45:54 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longlib.h"

void	map_checker(t_game *d)
{
	char	*s;
	int	i;

	s = d->big_line;
	i = d->player_pos;
	while (s[i] != 'C')
	{
		if (s[++i] == '1')
			continue ;
		if (s[--i] == '1')
			continue ;
		if (
		
	}
}
