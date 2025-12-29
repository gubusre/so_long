/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:42:39 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/09 23:57:29 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_aux(unsigned char *tmp_dst,
		unsigned char *tmp_src, size_t len)
{
	while (len > 0)
	{
		tmp_dst[len - 1] = tmp_src[len - 1];
		len--;
	}
	return (tmp_dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmp_src = (unsigned char *) src;
	tmp_dst = (unsigned char *) dst;
	i = 0;
	if (tmp_dst > tmp_src)
		tmp_dst = ft_aux(tmp_dst, tmp_src, len);
	else
	{
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (dst);
}
/* DESCRIPTION
       The  memmove() function copies n bytes from 
       memory area src to memory area dest.  The mem‐
       ory areas may overlap: copying takes place as 
       though the bytes in  src  are  first  copied
       into  a  temporary  array that does not overlap 
       src or dest, and the bytes are then copied
       from the temporary array to dest.

  RETURN VALUE
       The memmove() function returns a pointer to dest.
 * 
 * My_com
 * 	IF the first position of dst if higher than src we 
 * 	copy backwards, then even with the overlap we won't overwrite.
 * 	although if the first position of dst is lower than src 
 * 	we copy forward, will happen the same.
 * 	if their first positions are the same they would be the same, 
 * 	but even tho we copy in dst. 
 */
