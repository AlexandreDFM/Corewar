##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for corewar
##

NAME	=	corewar

SRC	=	src/main.c	\
		src/parse_flags.c	\
		src/read_champions.c	\
		src/parse_header.c	\
		src/free.c	\
		src/vm_init.c	\
		$(wildcard src/instructions/*.c)	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/ -lmy

INCLUDE	=	-I./include

CC	=	cc

RM	=	rm -rf

CFLAGS	=	-g3 -O2 -Wall -Wextra

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
