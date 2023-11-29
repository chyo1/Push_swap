RM=			rm -f
NAME=		push_swap
CC=			cc
CFLAGS=		-Wall -Wextra -Werror -g -fsanitize=address
SRCS_MAN=	main.c init_parsing.c init_connect_del.c init_divide.c init_make_asc.c init_make_desc.c\
			reverse_rotate.c rotate.c swap_n_push.c push_pop.c\
			merge.c merge_to_a.c merge_to_b.c
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS_MAN) -o $(NAME)

clean :

fclean :
	$(RM) $(NAME)

re :
	make fclean
	make all