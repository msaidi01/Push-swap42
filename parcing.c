/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:24:28 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/23 12:06:35 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

int	*parcing(int* ac, char **av)
{
	char	**args;
	char	*tmp;
	char	*nums;
	int	i;

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
