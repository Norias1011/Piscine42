NAME    = rush-02
SRCS    = main.c helper_functions.c filereader.c str_to_array_converter.c \
          str_to_arr_tools.c translator.c translator_helper.c number_printer.c \
          split_key_value.c cero_handler.c
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all fclean re