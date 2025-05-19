/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:09:33 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/15 12:15:22 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//a function to create a new list 
//after applying an external function to each node
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_list;
	t_list	*aux;
	void	*new_content;

	return_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		aux = ft_lstnew(new_content);
		if (!aux)
		{
			del(new_content);
			ft_lstclear(&return_list, del);
			return (NULL);
		}
		ft_lstadd_back(&return_list, aux);
		lst = lst->next;
	}
	return (return_list);
}
