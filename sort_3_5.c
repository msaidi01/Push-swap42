/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:51:21 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/23 11:22:35 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_max(t_list **stack)
{
	t_list	*tmp;
	int	i;

	tmp = (*stack);
	i = tmp->index;
	tmp = tmp->next;
	while (tmp)
	{
		if (i < tmp->index)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_3(t_list **stack)
{
	if (ft_lstsize(*stack) == 3)
	{
		if ((*stack)->index == ft_max(stack))
			ra(stack);
		else if ((*stack)->next->index == ft_max(stack))
			rra(stack);
	}
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

int	position(t_list	**stack, int i)
{
	t_list	*tmp;
	int	pos;

	pos = 1;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == i)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 1;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index == i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (position(stack_a, i) == 2)
			sa(stack_a);
		else if (position(stack_a, i) <= ft_lstsize(*stack_a) / 2)
			ra(stack_a);
		else if (position(stack_a, i) >= ft_lstsize(*stack_a) / 2)
			rra(stack_a);
	}
	if ((*stack_b)->index < (*stack_b)->next->index)
		rb(stack_b);
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	
}
