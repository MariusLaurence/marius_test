##
## EPITECH PROJECT, 2025
## Makefile
## File description:
##
##

SRC =	src/my_ls_a.c	\
	src/my_ls.c	\
	src/my_ls_d.c	\

OBJ =   $(SRC:.c=.o)

NAME =	my_ls

CC = epiclang

LIBFLAG = -L. -lmy

CPPFLAGS = -iquote include

all: $(NAME)

$(NAME):	make_lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFLAG)

make_lib:
	make -C lib/my

clean:
	$(RM) $(OBJ)

fclean: clean
	make -C lib/my fclean
	$(RM) $(NAME)

re: fclean all
