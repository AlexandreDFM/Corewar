##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for asm
##

NAME	=	asm

SRC	=	src/main.c				\
		src/op.c				\
		src/encoder.c			\
		src/write_file.c		\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/ -lmy

INCLUDE	=	-I./include

CC	=	cc

RM	=	rm -rf

CFLAGS	=	-g3 -Wall -Wextra

$(NAME)	:	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(INCLUDE) $(CFLAGS)

all	:	$(NAME)

clean	:
	make clean -C lib/
	$(RM) $(OBJ) *~ *# vgcore* *.cor

fclean	:	clean
	make fclean -C lib/
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
