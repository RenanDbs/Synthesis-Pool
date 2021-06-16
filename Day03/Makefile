##
## EPITECH PROJECT, 2021
## my_defender
## File description:
## Makefile
##

SRC	=	./main.c \
		./tool.c\
		./cook.c\
		./file_cases.c\
		./check_if_int.c\
		./create_save_file.c\
		./error_managements.c\
		./my_add_food_helper.c\

INC	=	-I./lib/

NAME	=	fridge

all:	$(NAME)

$(NAME):
		gcc $(SRC) $(INC) -o $(NAME) -lm -g3

clean:
		rm -f $(NAME)

fclean:	clean

re:	fclean	all