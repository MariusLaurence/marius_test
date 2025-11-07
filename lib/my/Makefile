##
## EPITECH PROJECT, 2025
## Makefile
## File description:
##
##

SRC =		mini_printf.c	\

OBJ = $(SRC:.c=.o)

NAME_LIB = libmy.a

NAME_HEADER = my.h

UNUSED_FLAG = -Wunused-command-line-argument

RM_FLAG = rm -f

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	mv libmy.a ../../

clean:
	$(RM_FLAG) $(OBJ)
	$(RM_FLAG) $(NAME_HEADER)

fclean: clean
	$(RM_FLAG) ../../$(NAME_LIB)

re: fclean all

.PHONY: all clean fclean re
