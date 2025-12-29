/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:28:39 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/15 16:56:54 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			digit = n + 48;
			write(fd, &digit, 1);
		}
	}
}
/*
int	main()
{
	ft_putnbr_fd(2134564, 1);
}
*/
/*
 * Desc
 * 	Write n to fd
 * 	Check INT_MIN, if negative write - and make number positive
 * 	make recursivity divided 10 for each number higher 
 * 	than 9 and extract the % of 10, after that transform the number 
 * 	to his corresponding number in ascii and write
 */
