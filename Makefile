RM=			rm -f
NAME=		push_swap
BONUS_NAME=	checker
CC=			cc
CFLAGS=		-Wall -Wextra -Werror -g
SRCS_MAN=	main.c\
			init_parsing_n_check_exception.c init_connect_del.c\
			under_6_code.c\
			init_divide.c init_make_asc.c init_make_desc.c init_make_asc_or_desc_6.c\
			init_divide_excep.c init_make_excep_asc.c init_make_excep_desc.c\
			merge.c merge_to_a.c merge_to_b.c\
			reverse_rotate.c rotate.c swap_n_push.c push_pop.c
SRCS_BONUS=	bonus_main.c\
			init_parsing_n_check_exception.c init_connect_del.c\
			bonus_reverse_rotate.c bonus_rotate.c bonus_swap_n_push.c push_pop.c\
			bonus_get_next_line.c bonus_get_next_line_utils.c
.PHONY : all clean fclean re

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(SRCS_MAN)
	$(CC) $(CFLAGS) $(SRCS_MAN) -o $(NAME)

$(BONUS_NAME) : $(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(BONUS_NAME)

clean :

fclean :
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re :
	make fclean
	make all