# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_Unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anttorre <anttorre@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 21:36:38 by W2Wizard          #+#    #+#              #
#    Updated: 2023/07/06 13:22:06 by anttorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

MLX42_MESSAGE_SHOWN := false

#//= Make Rules =//#
$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "$(CYAN)$(BOLD)Done.$(RESET)"
	
$(MLX42_MESSAGE_SHOWN):
	@echo "$(MAGENTA)$(BOLD)Compiling MLX42...$(RESET)"

%.o: %.c $(HDRS)
	@echo "$(MAGENTA)$(BOLD)Compiling:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)/mlx_%_shader.c: $(SHADER_DIR)/default.% $(MLX42_MESSAGE_SHOWN)
	@echo "$(BLUE)$(BOLD)Shader to C: $< -> $@$(RESET)"
	@bash tools/compile_shader.sh $< > $@

clean:
	@echo "$(RED)Cleaning objects from MLX42...$(RESET)"
	@rm -f $(OBJS) $(SHDR)
	@echo "$(GREEN)Done.$(RESET)"

fclean: clean
	@rm -f $(NAME)
