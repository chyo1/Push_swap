RM=			rm -f
NAME=		push_swap
CC=			cc
CFLAGS=		-Wall -Wextra -Werror -g -fsanitize=address
SRCS_MAN=	init_make_asc.c main.c push_pop.c reverse_rotate.c swap_n_push.c\
			init_connect_del.c init_make_desc.c merge.c parsing.c rotate.c
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