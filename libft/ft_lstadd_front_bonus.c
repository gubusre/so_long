/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:28:33 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/15 17:42:49 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list	*first_node = ft_lstnew(strdup("hola mundo"));
	if (!first_node)
		return (1);
	t_list	*second_node = ft_lstnew(strdup("cruel"));
	if (!second_node)
	{
		free(first_node->content);
		free(first_node);
		return (1);
	}
	ft_lstadd_front(&first_node, second_node);
	printf("%s\n", (char *)first_node->content);
}
*/
/*
 * Desc
 * 	Assign the "next" pointer to the first node of the list,
 * 	Assign the pointer to the first node to point new.
 *
 * My_com
 * 	"if what it's sent in new it's not what it's expected 
 * 	like the struct of t_list, might be good to check it?"
 */
