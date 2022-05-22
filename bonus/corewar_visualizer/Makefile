##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for the bonus
##

NAME	=	bonus

SRC	=	src/main.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/ -lmy

INCLUDE	=	-I./include/

CC	=	cc

RM	=	rm -rf

CFLAGS	=	-g3 -O2 -Wall -Wextra -lncurses

$(NAME)	:	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(INCLUDE) $(CFLAGS)

all	:	$(NAME)

clean	:
	make clean -C lib/
	$(RM) $(OBJ) *~ *# vgcore*

fclean	:	clean
	make fclean -C lib/
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
