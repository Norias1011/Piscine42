#!/bin/sh 

rm -f libft.a
find . -name "*.c" -type f -exec cc -Wall -Werror -Wextra -c {} \;
ar rc libft.a *.o
find . -name "*.0" -type f -delete
