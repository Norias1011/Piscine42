SRC = $(wildcard ../srcs/*.c)

OBJS = ${SRC:.c=.o}

NAME = bsq

all: ${NAME}
	

${NAME}: ${OBJS}
	cc -Wall -Wextra -Werror $^ -o $@

clean:  
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
