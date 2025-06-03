#!/bin/bash

cc -Wall -Wextra -Werror -c srcs/*.c -I includes
ar rc libft.a srcs/*.o
ranlib libft.a
