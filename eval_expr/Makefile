##
## Makefile for Makefile in /home/casoni_f//Projets/git/bistro/eval_expr
## 
## Made by fabien casoni
## Login   <casoni_f@epitech.net>
## 
## Started on  Thu Nov  8 11:07:39 2012 fabien casoni
## Last update Sun Nov 11 21:15:00 2012 fabien casoni
##

NAME=		bistro

CC=		cc

RM=		rm -f

SRC=		evalexpr.c \
		frpn.c \
		stack.c \
		struct_control.c \
		crpn.c \
		addition.c \
		operator.c

OBJ=		$(SRC:.c=.o)

LIB=		-lmy -L.

$(NAME):	$(OBJ)	
		$(CC) -o $(NAME) $(OBJ) $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all