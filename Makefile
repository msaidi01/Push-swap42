NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

FILES = push_swap.c parcing.c list_manage.c s.c r.c rr.c p.c sort_3_5.c sorting_algo.c

HEADER = push_swap.h

OBJ = $(FILES:.c=.o)

%.o : %.c  $(HEADER)
		cc $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	make -C libft
	cc $(OBJ) $(LIBFT) -o $(NAME)

all : $(NAME)

clean :
		make clean -C libft
		$(RM) $(OBJ)

fclean : clean
		make fclean -C libft
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re