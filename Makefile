# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 13:20:42 by marirodr          #+#    #+#              #
#    Updated: 2024/01/12 13:58:54 by marirodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

NAME_BONUS	=	cub3D_bonus

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -lm

LIBFT		=	libft/libft.a

MLX42		=	MLX42/libmlx42.a

SRC_DIR		=	src/
OBJ_DIR		=	objs/

SRC_DIR_BNS	=	src_bonus/
OBJ_DIR_BNS	=	objs_bonus/

#direccion de carpetas dentro de src/
#PARSE es la variable para los archivos sin extension de la carpeta de parseo
PARSE		=	parse read_file read_scene char_check wall_check scene_check get_map colour_handle

UTILS		=	clean_handling error_handling load_images candle collision window controls

RENDER		=	map paint player raycast 3Der


PARSE_BNS	=	parse read_file read_scene char_check wall_check scene_check get_map colour_handle_bonus

UTILS_BNS	=	clean_handling error_handling load_images candle collision window controls

RENDER_BNS	=	map_bonus paint_bonus player_bonus raycast_bonus 3Der_bonus

SRC			=	main.c \
				$(addsuffix .c, $(addprefix parser/, $(PARSE))) \
				$(addsuffix .c, $(addprefix utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix render/, $(RENDER))) \

SRC_BNS		=	main.c \
				$(addsuffix .c, $(addprefix parser_bonus/, $(PARSE))) \
				$(addsuffix .c, $(addprefix utils_bonus/, $(UTILS))) \
				$(addsuffix .c, $(addprefix render_bonus/, $(RENDER))) \


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_BNS		=	$(addprefix $(OBJ_DIR_BNS), $(SRC_BNS:.c=.o))

MLX_FLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

GREEN		=	\033[0;32m
RED			=	\033[0;31m
END			=	\033[0m

RM			=	rm -rf

all: $(NAME)
$(NAME): $(OBJ)
	@make -s -C libft
	@make -s -C MLX42
	@$(CC) $(CFLAGS) $(OBJ) $(MLX42) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled ✅$(END)"
				
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(OBJ_DIR)/parser $(OBJ_DIR)/utils $(OBJ_DIR)/render
	@$(CC) $(FLAGS) -c $< -o $@

#esto tambien hay que duplicarlo???

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)Compiled objects have been removed$(END)"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@make clean -C MLX42/
	@echo "$(RED)$(NAME) cleaned 🗑$(END)"

re: fclean all

bonus: $(OBJ_BNS)
	@make -s -C libft
	@make -s -C MLX42
	@$(CC) $(CFLAGS) $(OBJ_BNS) $(MLX42) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) compiled ✅$(END)"

clean_bonus:
	@$(RM) -rf $(OBJ_DIR_BNS)
	@echo "$(RED)Compiled objects from bonus have been removed$(END)"

fclean_bonus: clean_bonus
	@$(RM) $(NAME_BONUS)
	@make fclean -C libft
	@make clean -C MLX42/
	@echo "$(RED)$(NAME_BONUS) cleaned 🗑$(END)"

re_bonus: fclean_bonus bonus

norminette:
	@norminette src/ libft/ inc/
.PHONY: all, clean, fclean, re, bonus, norminette