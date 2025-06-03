NAME		= libft.a
SRC_DIR		= srcs
INCLUDE_DIR	= includes

SRCS		= $(SRC_DIR)/ft_putchar.c \
		  $(SRC_DIR)/ft_swap.c \
		  $(SRC_DIR)/ft_strlen.c \
		  $(SRC_DIR)/ft_strcmp.c
OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rc
RANLIB		= ranlib
RM		= rm -f

GREEN		= \033[0;32m
BLUE		= \033[0;34m
YELLOW		= \033[1;33m
RED		= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(BLUE)Creating archive... $(RESET)\n"
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	@printf "$(GREEN)Archive %s created successfully!$(RESET)\n" "$(NAME)"

.c.o:
	@printf "$(YELLOW)Compiling %s ... $(RESET)\n" "$<"
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@printf "$(RED)Object files removed$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Library %s removed$(RESET)\n" "$(NAME)"

re: fclean all

.PHONY: all clean fclean re
