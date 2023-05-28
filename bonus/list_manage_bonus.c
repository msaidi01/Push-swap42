/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:53:52 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/26 10:56:38 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = index;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next ;
// 		ft_lstdelone(*lst, del);
// 		(*lst) = tmp;
// 	}
// }
//  replace delone.
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
