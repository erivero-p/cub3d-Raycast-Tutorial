# COMPILER INFO
CC = cc
LIBFT_PATH = libft/
MLX_PATH = MLX42/
FLAGS = -Wall -Wextra -Werror -lm
MLX_FLAGS = -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBS =  -L$(LIBFT_PATH) $(MLX_PATH)


# GENERAL INFO
NAME = cub3d
SRC_DIR = src/
SRC = 
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# COLOR CODES
GREEN_CODE=\033[0;32m
RED_CODE=\033[0;31m
CEND_CODE=\033[0m

all: libft $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(MLX_FLAGS) $(LIBS) -o $(NAME) $(OBJ) libft/*.o
	@ echo "-->$(GREEN_CODE) $(NAME) compiled ✅ $(CEND_CODE)<--"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(MLX_FLAGS) -I $(INCLUDE_DIRS) -c $< -o $@

libft:
	@make -C libft/

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C libft/ clean
	@ echo "-->$(RED_CODE) $(NAME) cleaned 🗑 $(CEND_CODE)<--"

fclean: clean
	@$(RM) $(NAME) $(NAME_B)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re
