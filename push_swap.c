/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:10:27 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/23 12:08:35 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(int ac, int *arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1 && arr[i] != arr[j])
			j++;
		if (arr[i] == arr[j])
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		if (arr[i] > arr[i + 1])
			k = 0;
		i++;
	}
	if (k)
		exit(0);
}
int	ft_indexing(int *arr, int n, int ac)
{
	int	i;
	int	indx;
	
	i = 0;
	indx = 1;
	while(i < ac)
	{
		if (arr[i] < n)
			indx++;
		i++;
	}
	return (indx);

}
t_list	*fill_list(int ac, int* arr)
{
	t_list	*stack_a;
	int	indx;
	int	i;

	i = 0;
	stack_a = malloc(sizeof(t_list));
	stack_a = NULL;
	while(i < ac)
	{
		indx = ft_indexing(arr, arr[i], ac);
		ft_lstadd_back(&stack_a, ft_lstnew(arr[i], indx));
		i++;
	}
	return (stack_a);
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	arr = parcing(&ac , av);
	check_doubles(ac, arr);
	stack_a = fill_list(ac, arr);
	if (ft_lstsize(stack_a) <= 3)
		sort_3(&stack_a);
	else if (ft_lstsize(stack_a) <= 15)
		sort_5(&stack_a, &stack_b);
	else
		sorting_algo(&stack_a, &stack_b);
	// while(stack_a)
	// {
	// 	printf("cnt == %d,,,index == %d\n",stack_a->content, stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// while(stack_b)
	// {
	// 	printf("==============================0\n");
	// 	printf("cnt == %d,,,index == %d\n",stack_b->content, stack_b->index);
	// 	stack_b = stack_b->next;
	// }
}
