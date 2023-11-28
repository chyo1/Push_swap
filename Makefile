RM=			rm -f
NAME=		pushswap.a
CC=			cc
CFLAGS=		-Wall -Wextra -Werror
SRCS_MAN=	init_make_asc.c main.c push_pop.c reverse_rotate.c swap_n_push.c\
			init_connect_del.c init_make_desc.c merge.c parsing.c rotate.c
OBJS_MAN =  $(SRCS_MAN:.c=.o)
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS_MAN)
	ar rc $(NAME) $(OBJS_MAN)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./

clean :
	$(RM) $(OBJS_MAN)
	$(RM) $(OBJS_BONUS) 

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all