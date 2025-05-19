/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:05:20 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:07:55 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to add a node at the back (end) of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux_node = *lst;
	while (aux_node->next)
	{
		aux_node = aux_node->next;
	}
	aux_node->next = new;
}
