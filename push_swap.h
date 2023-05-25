/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:08:24 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/25 19:19:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../Push_swap/libft/libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

int *parcing(int* ac, char **av);
void	check_doubles(int ac, int *arr);
t_list	*ft_lstnew(int content, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sa(t_list **nums);
void	sb(t_list **nums);
void	ss(t_list **stack_a, t_list	**stack_b);
void    rotation_ft(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rot(t_list	**stack);
void	rra(t_list	**stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void    push_ft(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list	**stack_b);
void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sorting_algo(t_list **stack_a, t_list **stack_b);
int		position(t_list	**stack, int i);
void	ft_error(void);
// void	ft_lstclear(t_list **lst, void (*del)(void *));
int	ft_lstsize(t_list *lst);

#endif