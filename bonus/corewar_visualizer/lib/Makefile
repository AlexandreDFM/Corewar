##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for the library
##

NAME	=	libmy.a

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
	$(RM) $(OBJ) *~ *# vgcore*

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
