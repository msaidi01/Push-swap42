/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:25:54 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/25 19:28:52 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rot(t_list	**stack)
{
	t_list	*tmp;
	int	i;

	i = ft_lstsize(*stack);
	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	*stack = tmp;
	while(i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	rra(t_list	**stack_a)
{
	reverse_rot(stack_a);
}

void	rrb(t_list **stack_b)
{
	reverse_rot(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
