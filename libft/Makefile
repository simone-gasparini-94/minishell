CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fPIC
INC			= -Iinc
NAME		= libft.a
SRC_DIR		= src
OBJ_DIR		= build

SRC			= $(wildcard $(SRC_DIR)/*.c)
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

