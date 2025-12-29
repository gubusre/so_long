/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:11:21 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/12 21:30:18 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			cc;

	cc = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *) &s[i];
		i++;
	}
	if (cc == '\0')
		res = (char *) &s[i];
	return (res);
}
/*
 * Desc
 * 	The strrchr() function returns a pointer to 
 * 	the last occurrence of the character c in the string s.
 *
 * Return
 * 	strrchr()  functions return a pointer to the matched character 
 * 	or NULL if the character is not found.  The terminating null byte 
 * 	is considered part of the string, so that if c is
 *      specified as '\0', these functions return a pointer to the terminator.
 *
 * My_com
 * 	Iterate and copy to res if found, overwrite res if found later.
 */
