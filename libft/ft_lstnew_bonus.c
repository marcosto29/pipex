/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:47:55 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:17:33 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//t_list *node is a complex pointer that points both the content and next
//to initialized it is the same way any other pointer
//to acces the data same thing happens *node->content or *node->next
//but something important in this type of structs where the base data is void
//is to cast them before use them *(int *)node->content

//function to create a new node of T type
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) ft_calloc(sizeof(t_list), 1);
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}
