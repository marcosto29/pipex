/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:04:36 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/29 18:57:41 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to get the last node of a list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux_node;

	if (!lst)
		return (NULL);
	aux_node = lst;
	while (aux_node->next)
	{
		aux_node = aux_node->next;
	}
	return (aux_node);
}
