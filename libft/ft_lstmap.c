/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:58:07 by ccolin            #+#    #+#             */
/*   Updated: 2024/05/07 09:36:47 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	head = new;
	while (lst)
	{
		lst = lst->next;
		if (lst == NULL)
			break ;
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
			ft_lstclear(&head, del);
		new = new->next;
	}
	new->next = NULL;
	return (head);
}
