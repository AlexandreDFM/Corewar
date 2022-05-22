##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile for corewar project
##

all	:
	make -C asm/
	make -C bonus/corewar_visualizer/
	make -C corewar/

clean	:
	make clean -C asm/
	make clean -C bonus/corewar_visualizer/
	make clean -C corewar/

fclean	:	clean
	make fclean -C asm/
	make fclean -C bonus/corewar_visualizer/
	make fclean -C corewar/

re	:	fclean all

.PHONY	:	all clean fclean re
