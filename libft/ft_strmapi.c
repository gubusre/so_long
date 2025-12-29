/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:18:22 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/14 17:54:12 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
#include <stdio.h>

char	f(unsigned int i, char c)
{
	return (ft_toupper(c) + i - i);
}

int	main()
{
	const char	*s;

	s = "hola mundo";
	printf("%s\n", s);
	printf ("%s\n", ft_strmapi(s, f));
	return (0);
}
*/
/*
 * Desc
 * 	Apply f to all chars of s.
 *
 * Return
 * 	string after f applited to whole s string.
 */
