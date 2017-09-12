CC	?= gcc

CFLAGS	=  -g -O0
LFLAGS	=
WARN	= -Wall -Wextra -Werror

SRC	= link_one_way.c test.c
DEPS	= link_one_way.h

NAME	= link

.PHONY: test

test: $(SRC) $(DEPS)
	$(CC) $(WARN) $(CFLAGS) $(LFLAGS) $(SRC) -o $(NAME)
