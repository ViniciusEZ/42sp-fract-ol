CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror 
OPT_FLAGS = -march=native -O3 -flto \
			-funroll-loops -fomit-frame-pointer \
			-fno-math-errno -fno-trapping-math -ffinite-math-only
MLX_DIR		:= minilibx-linux
MLX_LIB		:= $(MLX_DIR)/libmlx.a
MLX_FLAGS	:= -I$(MLX_DIR) $(MLX_LIB) -lX11 -lXext -lm -lz

NAME		:= fractol

SRC_DIR		:= .
OBJ_DIR		:= obj

SRC			:= burning_ship.c colors.c colors_utils.c fractol.c \
			   hooks.c hooks_utils.c julia.c mandelbrot.c \
			   plane.c sets.c tricorn.c utils.c zoom_utils.c \
			   validations.c

OBJ			:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP			:= $(OBJ:.o=.d)


all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OPT_FLAGS) -I$(MLX_DIR) $(OBJ) $(MLX_FLAGS) -o $@
	@echo "Linked"

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OPT_FLAGS) -I$(MLX_DIR) -MMD -MP -c $< -o $@
	@echo "Compiled: $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1 || true
	@rm -rf $(MLX_DIR)
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Binary removed."

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
