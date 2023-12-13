/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiguera <ahiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:57:47 by ahiguera          #+#    #+#             */
/*   Updated: 2023/10/21 12:43:31 by ahiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*result_list;
	void	*content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_node = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		result_list = ft_lstnew(content);
		if (result_list == NULL)
		{
			del(content);
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node, result_list);
		lst = lst->next;
	}
	return (new_node);
}
