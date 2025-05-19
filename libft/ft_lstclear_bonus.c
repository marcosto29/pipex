/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:07:39 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:11:24 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to cleanly delete the list with an external delete function
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_node;

	while (*lst)
	{
		current_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current_node, del);
	}
}
