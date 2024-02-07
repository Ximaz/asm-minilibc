##
## EPITECH PROJECT, 2023
## minilibc
## File description:
## Makefile
##

NAME		:=	libasm.so
RM			:=	rm -rf
NASM		:=	nasm
NASM_FLAGS	:=	-g -Wall -Werror -f elf64 -O0 -DCRITERION=0
CC			:=	gcc
CFLAGS		:=	-g -Wall -Wno-nonnull
SRCS		:=	$(shell find src -type f -name '*.asm')
OBJS		:=	$(SRCS:.asm=.o)
TESTS_SRCS	:=	$(shell find tests -type f -name 'tests_*.c')
TESTS_OBJS	:=	$(TESTS_SRCS:.c=.o)

%.o: %.asm
	$(NASM) $(NASM_FLAGS) $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	ld -shared $(OBJS) -o $(NAME)

tests_run:	$(OBJS) $(TESTS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TESTS_OBJS) -o unit_tests -lcriterion
	./unit_tests

main:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o program
	./program

clean:
	$(RM) $(OBJS)
	$(RM) $(TESTS_OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) unit_tests

re:	fclean	all

.PHONY: all clean fclean re
