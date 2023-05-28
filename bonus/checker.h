/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:41:21 by msaidi            #+#    #+#             */
/*   Updated: 2023/05/27 13:50:27 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
t_list	*ft_lstnew(int content, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	push_ft(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list	**stack_b);
void	rotation_ft(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rot(t_list	**stack);
void	rra(t_list	**stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	swap(t_list	**nums);
void	sa(t_list **nums);
void	sb(t_list **nums);
void	ss(t_list **stack_a, t_list	**stack_b);
char	**ft_split(char const *s, char c, int *len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif