NAME	= bsq

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC	= main.c ft_solution.c ft_check_map.c ft_read_map.c ft_print.c ft_strlen.c ft_strcpy.c ft_char.c

all: $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
