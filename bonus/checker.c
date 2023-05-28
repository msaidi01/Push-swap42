/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:55:41 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/28 16:33:20 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	chkdigit(char *to_test)
{
	int	i;

	i = 0;
	while (to_test[i])
	{
		if (to_test[i] != ' ')
			return ;
		i++;
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	*check_args(char **args, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int *) * len);
	while (i < len)
	{
		arr[i] = ft_atoi(args[i]);
		i++;
	}
	return (arr);
}

int	*parcing(int *ac, char **av)
{
	char	**args;
	char	*tmp;
	char	*nums;
	int		i;

	i = 1;
	nums = NULL;
	while (i <= *ac)
	{
		tmp = nums;
		nums = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	i = 0;
	while (av[i])
	{
		chkdigit(av[i]);
		i++;
	}
	args = ft_split(nums, ' ', &i);
	*ac = i;
	free(nums);
	return (check_args(args, i));
}

void	dis_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

int	ft_indexing(int *arr, int n, int ac)
{
	int	i;
	int	indx;

	i = 0;
	indx = 1;
	while (i < ac)
	{
		if (arr[i] < n)
			indx++;
		i++;
	}
	return (indx);
}

t_list	*fill_list(int ac, int *arr)
{
	t_list	*stack_a;
	int		indx;
	int		i;

	i = 0;
	stack_a = malloc(sizeof(t_list));
	stack_a = NULL;
	while (i < ac)
	{
		indx = ft_indexing(arr, arr[i], ac);
		ft_lstadd_back(&stack_a, ft_lstnew(arr[i], indx));
		i++;
	}
	return (stack_a);
}

void	check_doubles(int ac, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < ac - 1)
	{
		while (j < ac - 1 && arr[i] != arr[j])
			j++;
		if (arr[i] == arr[j])
			dis_error();
		i++;
	}
}

void	check_s(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strcmp(inst, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(inst, "sb\n"))
		sa(stack_a);
	else if (!ft_strcmp(inst, "ss\n"))
		ss(stack_a, stack_b);
}

void	check_r(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (ft_strcmp(inst, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(inst, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(inst, "ss\n") == 0)
		rr(stack_a, stack_b);
}

void	check_rr(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (ft_strcmp(inst, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(inst, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(inst, "rrr\n") == 0)
		rrr(stack_a, stack_b);
}

void	check_p(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (ft_strcmp(inst, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(inst, "pb\n") == 0)
		pb(stack_a, stack_b);
}

void	is_sorted(t_list **stack)
{
	if (!(*stack))
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	while ((*stack)->next)
	{
		if ((*stack)->content > (*stack)->next->content)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		*stack = (*stack)->next;
	}
}

void	instruction_check(t_list **stack_a, t_list **stack_b, char *inst)
{
	if (!ft_strcmp(inst, "sa\n")
		|| !ft_strcmp(inst, "sb\n") || !ft_strcmp(inst, "ss\n"))
		check_s(stack_a, stack_b, inst);
	else if (!ft_strcmp(inst, "ra\n") || !ft_strcmp(inst, "rb\n")
		|| !ft_strcmp(inst, "rr\n"))
		check_r(stack_a, stack_b, inst);
	else if (!ft_strcmp(inst, "rra\n") || !ft_strcmp(inst, "rrb\n")
		|| !ft_strcmp(inst, "rrr\n"))
		check_rr(stack_a, stack_b, inst);
	else if (!ft_strcmp(inst, "pa\n") || !ft_strcmp(inst, "pb\n"))
		check_p(stack_a, stack_b, inst);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*inst;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	arr = parcing(&ac, av);
	check_doubles(ac, arr);
	stack_a = fill_list(ac, arr);
	inst = get_next_line(0);
	while (inst)
	{
		instruction_check(&stack_a, &stack_b, inst);
		free(inst);
		inst = get_next_line(0);
		if (!inst)
			break ;
	}
	is_sorted(&stack_a);
	if (stack_b)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	else
		write(1, "OK\n", 3);
}
