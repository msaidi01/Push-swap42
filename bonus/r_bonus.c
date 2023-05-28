/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:47:37 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/27 17:05:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotation_ft(t_list **stack)
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
	if (ft_lstsize(*stack_a) >= 2)
		rotation_ft(stack_a);
}

void	rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) >= 2)
		rotation_ft(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) >= 2 && ft_lstsize(*stack_b) >= 2)
	{
		rotation_ft(stack_a);
		rotation_ft(stack_b);
	}
}
