/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:39:33 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/14 17:43:38 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*m_alloc(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

static size_t	int_len(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*w_str(char *n_str, long nbr, size_t len)
{
	size_t	i;

	i = len - 1;
	while (nbr != 0)
	{
		n_str[i] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	char	*n_str;
	size_t	len;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	n_str = m_alloc(len);
	if (!n_str)
		return (NULL);
	if (nbr == 0)
	{
		n_str[0] = '0';
		n_str[1] = '\0';
		return (n_str);
	}
	if (nbr < 0)
		nbr = -nbr;
	n_str[len] = '\0';
	if (n < 0)
		n_str[0] = '-';
	n_str = w_str(n_str, nbr, len);
	return (n_str);
}
/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(NULL));
	return (0);
}
*/
/* Desc
 *	int to ascii 
 * Return
 * 	string of n 
 */
