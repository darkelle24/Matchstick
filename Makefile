##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c					\
		src/ai.c 					\
		src/chartoint.c				\
		src/check_recup_param.c 	\
		src/jeu.c 					\
		src/my_put_nbr.c 			\
		src/my_str_isnum.c 			\
		src/my_strlen.c 			\
		src/player_1.c				\
		src/player_2.c 				\
		src/player.c 				\
		src/prep_toolbox.c 			\
		src/print_game_board.c 		\
		src/print_win_and_result.c 	\
		src/readoutput.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

spe:	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re


##CFLAGS	=	-ggdb