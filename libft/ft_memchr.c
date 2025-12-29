/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:44:03 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/09 20:07:25 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	str = (unsigned char *) s;
	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
/*
 *DESCRIPTION
 *      The  memchr()  function  scans  the  initial n bytes of the memory area
 *      pointed to by s for the first instance of c.  Both c and the  bytes  of
 *      the memory area pointed to by s are interpreted as unsigned char.
 *RETURN VALUE
 *      The  memchr()  and memrchr() functions return a pointer to the matching
 *      byte or NULL if the character does not occur in the given memory area.
 *
 * My_com:
 * 	Transforms to unsigned char and compares from start 
 * 	to n until find the same or NULL 
 * 	if found returns de pointer at the position 
 * 	found being and undermined type (void *)
 */
