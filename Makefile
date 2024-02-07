##
## EPITECH PROJECT, 2023
## minilibc
## File description:
## Makefile
##

NAME	:=	libasm.so
RM		:=	rm -rf
FLAGS	:=	-g -Wall -Werror -f elf64 -O0
SRCS	:=	$(shell find src -type f -name '*.asm')
OBJS	:=	$(SRCS:.asm=.o)

%.o: %.asm
	nasm $(FLAGS) $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -g -shared -fPIC $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
