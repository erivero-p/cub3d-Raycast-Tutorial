# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 13:20:42 by marirodr          #+#    #+#              #
#    Updated: 2024/01/09 12:59:22 by marirodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror -lm

LIBFT		=	libft/libft.a

MLX42		=	MLX42/libmlx42.a

SRC_DIR		=	src/
OBJ_DIR		=	objs/

#direccion de carpetas dentro de src/
#PARSE es la variable para los archivos sin extension de la carpeta de parseo
PARSE		=	parse read_file read_scene char_check wall_check scene_check get_map colour_handle

UTILS		=	clean_handling error_handling debug load_images candle

SETTING		=	window controls

MAP			=	map paint player

RAYCAST		= 	raycast 3Der

COLLISION	=	collision

SRC			=	main.c \
				$(addsuffix .c, $(addprefix parser/, $(PARSE))) \
				$(addsuffix .c, $(addprefix utils/, $(UTILS))) \
				$(addsuffix .c, $(addprefix settings/, $(SETTING))) \
				$(addsuffix .c, $(addprefix map/, $(MAP))) \
				$(addsuffix .c, $(addprefix raycast/, $(RAYCAST))) \
				$(addsuffix .c, $(addprefix collision/, $(COLLISION))) \
#con la linea de arriba le añadimos primero la extension .c a los archivos, le añadimos la ruta de la carpeta donde se encuentra y llamamos a ssu variable correspondiente


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

MLX_FLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

GREEN		=	\033[0;32m
RED			=	\033[0;31m
END			=	\033[0m

RM			=	rm -rf

BONUS		=	0

#esto es lo que se llama directiva condicional de Makefile. Si la variable BONUS = 1, entonces se añade -DBONUS a la varibale CFLAGS. -DBONUS es una opcion del compilador que define una macro llamada BONUS, que puede ser usado en el codigo fuente para condicionar la compilacion de ciertas partes del codigo
ifeq ($(BONUS), 1)
	CFLAGS += -DBONUS
endif

all: $(NAME)
$(NAME): $(OBJ)
	@make -s -C libft
	@make -s -C MLX42
#-DBONUS=$(BONUS): con esta 'regla' el compilador define una macro llamada BONUS y le asigna el valor de la variable BONUS de Makefile y puede ser usado en el codigo fuente.
	@$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJ) $(MLX42) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
#	dentro de una regla en vez de usarse 'ifeq' se deben usar comandos de shell. en este caso usamos el comando if de shell que lo que hace es comprobar si BONUS es igual a 0 y en ese caso imprime el mensaje
	@if [ $(BONUS) -eq 0 ]; then echo "$(GREEN)$(NAME) compiled ✅$(END)"; fi
				
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
#cada vez que queramos añadir una carpeta, utilizamos una linea similar a la de abajo para dentro de la carpeta /objs ir añadiendolos todos
	@mkdir -p $(OBJ_DIR)/parser $(OBJ_DIR)/utils $(OBJ_DIR)/settings $(OBJ_DIR)/map $(OBJ_DIR)/raycast $(OBJ_DIR)/collision
	@$(CC) $(FLAGS) -DBONUS=$(BONUS) -c $< -o $@
# no se si en la linea de arriba tenemos que llamar a $(MLX_FLAGS)


clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)Compiled objects have been removed$(END)"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@make clean -C MLX42/
	@echo "$(RED)$(NAME) cleaned 🗑$(END)"

re: fclean all

# la regla bonus basicamente limpia lo anterior y recompila el codigo con la variable BONUS establecida en 1 para asi poder usarla en el codigo fuente.
bonus:
	@make re BONUS=1
	@echo "$(GREEN)$(NAME) with bonus compiled ✅$(END)"

.PHONY: all, clean, fclean, re