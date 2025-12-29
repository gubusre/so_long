/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:16:36 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/09 23:06:18 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) b;
	while (len-- > 0)
		*(tmp_ptr++) = (unsigned char) c;
	return (b);
}
/*DESCRIPTION
       The  memset() function fills the first n bytes 
       of the memory area pointed to by s with the
       constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.

*/
