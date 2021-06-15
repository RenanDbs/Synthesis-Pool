##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	./main.c \
		./my_str_to_word_array.c\
		./my_get.c\
		./my_get_helper.c\

INC	=	-I./lib/

NAME	=	my_db

all:	$(NAME)

$(NAME):
		gcc $(SRC) $(INC) -o $(NAME) -lm -g3

clean:
		rm -f $(NAME)

fclean:	clean

re:	fclean	all