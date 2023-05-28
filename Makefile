# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 11:45:19 by msaidi            #+#    #+#              #
#    Updated: 2023/05/28 19:12:31 by msaidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

BONUS = checker

FILES = push_swap.c parcing.c list_manage.c s.c r.c rr.c p.c sort_3_5.c sorting_algo.c

FILES_B = bonus/checker.c bonus/ft_strcmp.c bonus/list_manage_bonus.c bonus/s_bonus.c \
		 bonus/r_bonus.c bonus/rr_bonus.c bonus/p_bonus.c bonus/ft_split.c bonus/ft_strjoin.c \
		 bonus/ft_atoi_bonus.c bonus/gnl_bonus.c bonus/gnl_utils_bonus.c

HEADER = push_swap.h

HEADER_B = checker.h

OBJ = $(FILES:.c=.o)

OBJ_B = $(FILES_B:.c=.o)

%.o : %.c  $(HEADER)
		cc $(CFLAGS) -c -o $@ $<

%.o : %.c  $(HEADER_B)
		cc $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	make -C libft
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS) : $(FILES_B)
	cc $(FILES_B) -o $(BONUS)

all : $(NAME)

bonus : $(BONUS)

clean :
		make clean -C libft
		$(RM) $(OBJ)

fclean : clean
		make fclean -C libft
		$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus