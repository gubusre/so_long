/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:34:26 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/12 20:59:06 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
 * Desc
 * 	Takes node 'lst' as a parameter and free
 * 	the memory from the content using fuction (del)
 * 	given as a parameter, and free the node too.
 *	Memory of next must not be freed.
 *
 * My_com
 * 	So first we will free the content of the node 
 * 	using the function "del" "del funciton asks for a (void *)"
 * 	after done if done we will free the node ref this 
 * 	to the "next node".
 */
