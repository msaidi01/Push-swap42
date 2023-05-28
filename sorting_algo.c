/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:32:38 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/27 19:17:20 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_stack_b(t_list **stack_a, t_list **stack_b, int pvt1, int pvt2)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if (ft_lstsize(*stack_b) == pvt1)
		{
			pvt2 = ft_lstsize(*stack_a) / 6 + pvt1;
			pvt1 = ft_lstsize(*stack_a) / 3 + pvt1;
		}
		if ((*stack_a)->index > pvt1
			&& (ft_lstsize(*stack_b) > 1 && (*stack_b)->index <= pvt2))
			rr(stack_a, stack_b);
		else if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index <= pvt2)
			rb(stack_b);
		if ((*stack_a)->index <= pvt1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

int	pushing_from_the_top(t_list **stack_a, t_list **stack_b, int flag)
{
	while ((*stack_b)->index != (*stack_a)->index - 1)
	{
		if (flag == 0 || (*stack_b)->index > ft_lstlast(*stack_a)->index)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			flag = 1;
		}
		else
			rb(stack_b);
	}
	pa(stack_a, stack_b);
	return (flag);
}

int	pushing_from_the_bot(t_list **stack_a, t_list **stack_b, int flag)
{
	while ((*stack_b)->index != (*stack_a)->index - 1)
	{
		if (flag == 0 || (*stack_b)->index > ft_lstlast(*stack_a)->index)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			flag = 1;
		}
		else
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
	return (flag);
}

void	to_stack_a(t_list **stack_a, t_list **stack_b, int flag)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		else if (ft_lstlast(*stack_b)->index == (*stack_a)->index - 1)
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
		else if (position(stack_b,
				(*stack_a)->index - 1) <= ft_lstsize(*stack_b) / 2)
			flag = pushing_from_the_top(stack_a, stack_b, flag);
		else if (position(stack_b,
				(*stack_a)->index - 1) > ft_lstsize(*stack_b) / 2)
			flag = pushing_from_the_bot(stack_a, stack_b, flag);
		while (ft_lstlast(*stack_a)->index == (*stack_a)->index - 1)
			rra(stack_a);
		if (ft_lstlast(*stack_a)->index > (*stack_a)->index)
			flag = 0;
	}
}

void	sorting_algo(t_list **stack_a, t_list **stack_b)
{
	int	pvt1;
	int	pvt2;
	int	flag;

	flag = 0;
	pvt2 = ft_lstsize(*stack_a) / 6;
	pvt1 = ft_lstsize(*stack_a) / 3;
	to_stack_b(stack_a, stack_b, pvt1, pvt2);
	sort_3(stack_a);
	to_stack_a(stack_a, stack_b, flag);
}
