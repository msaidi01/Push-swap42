/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:47:37 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/22 14:03:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotation_ft(t_list **stack)
{
	t_list	*tmp;
	
	if (!(*stack))
		return ;
	tmp = ft_lstlast(*stack);
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}
void	ra(t_list **stack_a)
{
	if ((*stack_a)->next)
	{
		rotation_ft(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	if ((*stack_b)->index)
	{
		rotation_ft(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next && (*stack_b)->next)
	{
		rotation_ft(stack_a);
		rotation_ft(stack_b);
		write(1, "rr\n", 3);
	}
}