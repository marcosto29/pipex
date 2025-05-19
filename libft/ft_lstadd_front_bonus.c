/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:53:32 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:08:11 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to add a node at the front (beggining) of the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old_node;

	old_node = *lst;
	*lst = new;
	new->next = old_node;
}
