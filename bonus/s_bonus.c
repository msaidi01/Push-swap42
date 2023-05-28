/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:50:56 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/27 17:05:21 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (ft_lstsize(*nums) >= 2)
		swap(nums);
}

void	sb(t_list **nums)
{
	if (ft_lstsize(*nums) >= 2)
		swap(nums);
}

void	ss(t_list **stack_a, t_list	**stack_b)
{
	if (ft_lstsize(*stack_a) >= 2 && ft_lstsize(*stack_b) >= 2)
	{
		sa(stack_a);
		sb(stack_b);
	}
}
