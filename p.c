/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:30:14 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/23 12:05:05 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ft(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	tmp = (*stack_1);
	if (!(*stack_1)->next)
	{
		(*stack_1) = NULL;
	}
	else
	(*stack_1) = (*stack_1)->next;
	tmp->next = (*stack_2);
	*stack_2 = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push_ft(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list	**stack_b)
{
	push_ft(stack_a, stack_b);
	write(1, "pb\n", 3);
}
