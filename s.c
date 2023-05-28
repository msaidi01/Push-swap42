/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:50:56 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/27 19:18:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**nums)
{
	t_list	*node1;
	t_list	*node2;

	node1 = *nums;
	node2 = (*nums)->next;
	*nums = (*nums)->next->next;
	ft_lstadd_front(nums, node1);
	ft_lstadd_front(nums, node2);
}

void	sa(t_list **nums)
{
	if ((*nums)->next)
	{
		swap(nums);
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **nums)
{
	if ((*nums)->next)
	{
		swap(nums);
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list	**stack_b)
{
	if ((*stack_a)->next && (*stack_b)->next)
	{
		sa(stack_a);
		sb(stack_b);
		write(1, "ss\n", 3);
	}
}
