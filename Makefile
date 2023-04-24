##
## EPITECH PROJECT, 2023
## myftp
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/launch_battle.c	\
		src/arguments/parse_args.c	\
		src/arguments/fill_infos.c	\
		src/utils/array_len.c	\
		src/utils/villagers_fighting.c	\

OBJ	=	$(SRC:.c=.o)

SRC_MAIN	=	src/main.c	\

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

SRC_TESTS	=

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

CPPFLAGS	=	-I./include/

CFLAGS	=	-W -Wall -Wextra -pedantic

LDLIBS	=	-lpthread

NAME	=	panoramix

NAME_TESTS	=	unit_tests

all: $(NAME)
.PHONY: all

$(NAME): $(OBJ) $(OBJ_MAIN)
	@$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN)

debug: CFLAGS += -g
debug: $(NAME)
.PHONY: debug

clean:
	@find -name "*.o" -delete
	@find -name "*.gc*" -delete
.PHONY: clean

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_TESTS)
.PHONY: fclean

tests_run:	CFLAGS		+= -fprofile-arcs -ftest-coverage
tests_run:	LDLIBS		+=	-lcriterion	-lgcov
tests_run:	CPPFLAGS	+= --coverage
tests_run:	fclean $(OBJ) $(OBJ_TESTS)
	$(CC) -o $(NAME_TESTS) $(OBJ) $(OBJ_TESTS) $(LDLIBS)
	-./$(NAME_TESTS) ; gcovr --exclude tests ; gcovr --exclude tests --branches
.PHONY:	tests_run

re:	fclean all
.PHONY:	re
