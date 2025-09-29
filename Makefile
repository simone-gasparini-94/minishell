CC 			= 	cc
FLAGS		=	-g -Wall -Wextra -Werror 
INCS		=	-Iinc											\
				-Ilibft/inc
SRC_DIR		=	src
OBJ_DIR		=	build
SRCS		=	banner.c										\
				bin.c											\
				built_in.c										\
				cd.c											\
				clean.c											\
				cmds.c											\
				data.c											\
				echo.c											\
				env.c											\
				execute.c										\
				exit.c											\
				expand.c										\
				export.c										\
				file_descriptors.c								\
				files.c											\
				free.c											\
				interpret.c										\
				list.c											\
				main.c											\
				operators.c										\
				path.c											\
				pipes.c											\
				pwd.c											\
				signals.c										\
				token.c											\
				token_count.c									\
				token_trim.c									\
				token_quotes.c									\
				unset.c											\
				utils.c
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIBFT		=	-Llibft -lft
READLINE	=	-lreadline
NAME		=	minishell

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
