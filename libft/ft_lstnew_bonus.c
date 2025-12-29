/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubusque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:26:56 by gubusque          #+#    #+#             */
/*   Updated: 2025/04/15 18:50:02 by gubusque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>

int	main()
{
	int	i = 2;
	void *ptr = &i;
	printf("%s\n", (char *)ft_lstnew(NULL)->content);
	printf("%d\n", *(int *) ft_lstnew(ptr)->content);
	printf("%s\n", (char *)ft_lstnew("hola")->content);
}

 *
 * Desc
 * 	creates new node using malloc,
 * 	content intialized with content, next init with NULL.
 *
 * Return
 * 	pointer to node or NULL.
 * */
