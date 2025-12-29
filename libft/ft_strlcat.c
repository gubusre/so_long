/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:44:54 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/09 18:56:06 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dst_size)
		dst_len = dst_size;
	if (dst_len == dst_size)
		return (dst_size + src_len);
	if (src_len < dst_size - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dst_size - dst_len - 1);
		dst[dst_size - 1] = '\0';
	}
	return (dst_len + src_len);
}
/*
 * Desc
 * 	Copy src to dst, 
 * 	if dst can't handle the whole size 
 * 	only copy dst_size - (dst_len + NULL)
 *
 * Return
 * 	Size of the string tries to create.
 */
