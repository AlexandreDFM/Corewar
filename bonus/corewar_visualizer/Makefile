##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for the bonus
##

NAME	=	bonus

SRC	=	src/main.c							\
		src/launch_visu.c					\
		src/parse_champions.c				\
		src/parse_flags.c					\
		src/parse_header.c					\
		src/vm_init.c						\
		src/vm_run.c						\
		src/free.c							\
		$(wildcard src/instructions/*.c)	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/ -lmy

INCLUDE	=	-I./include/

CC	=	cc

RM	=	rm -rf

CFLAGS	=	-O2 -Wall -Wextra -lncurses -lcsfml-audio

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
