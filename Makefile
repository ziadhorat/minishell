NAME = minishell

LIBFT_PATH = ./libft/

SRC_PATH = ./srcs/

SRC_NAME =	main.c prompt.c env.c exec.c parse.c cmd.c bin/cd.c bin/env_b.c \
			bin/setenv.c bin/unsetenv.c bin/echo.c

FLAGS = -Wall -Werror -Wextra

INC =  -I ./includes/minishell.h -I $(LIBFT_PATH)libft.h

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRCO)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT_PATH)libft.a -lreadline
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re
