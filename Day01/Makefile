##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	./main.c \
		./open_folder.c\
		./my_str_to_word_array.c\
		./struct_work.c\
		./gameloop.c\
		./gameloop_helper.c\

INC	=	-I./lib/

NAME	=	pokemon

all:	$(NAME)

$(NAME):
		gcc $(SRC) $(INC) -o $(NAME) -lm -g3

clean:
		rm -f $(NAME)

fclean:	clean

re:	fclean	all