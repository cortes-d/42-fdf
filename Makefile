# ANSI color codes for pretty output
COLOR_GREEN = \033[0;32m
COLOR_RESET = \033[0m

# Directories
DIR_INC = inc
DIR_SRC = src

# Compilation settings
NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(DIR_INC)
RM = rm -f

# Source files for the main project
DIR_UTIL = $(DIR_SRC)/util/
DIR_DATA = $(DIR_SRC)/data/
DIR_GRAPHIC = $(DIR_SRC)/graphic/
DIR_HOOK = $(DIR_SRC)/hook/

SRC_MAIN = 		fdf.c
SRC_UTIL = 		get_next_line.c \
				atoi_hex.c \
				to_radians.c

SRC_DATA = 		free.c \
				map_arr_count_cols.c \
				map_arr_free.c \
				map_arr_init.c \
				map_arr_to_pts.c \
				map_arr_void.c \
				map_arr_zero.c \
				map_fil_iter.c \
				map_fil_read.c \
				map_pts_color_init.c \
				map_pts_copy.c \
				map_pts_free.c \
				map_pts_init.c \
				map_pts_iter.c \
				map_pts_transform.c

SRC_GRAPHIC = 	gfx_flood_fill.c \
				gfx_put_background.c \
				gfx_put_line.c \
				gfx_put_pixel.c \
				gfx_render.c

SRC_HOOK = 		hook_action.c \
				hook_key.c \
				hook_mouse.c \
				hook_window_close.c \
				hook_window_move.c

SRC_MAIN := $(addprefix $(DIR_SRC)/, $(SRC_MAIN))
SRC_UTIL := $(addprefix $(DIR_UTIL), $(SRC_UTIL))
SRC_DATA := $(addprefix $(DIR_DATA), $(SRC_DATA))
SRC_GRAPHIC := $(addprefix $(DIR_GRAPHIC), $(SRC_GRAPHIC))
SRC_HOOK := $(addprefix $(DIR_HOOK), $(SRC_HOOK))

# Combine all source files
SRC = $(SRC_MAIN) $(SRC_UTIL) $(SRC_DATA) $(SRC_GRAPHIC) $(SRC_HOOK)

# Object files
OBJ = $(SRC:.c=.o)

# Define libraries with their settings
LIBRARIES = libft mlx

LIBFT_DIR = $(DIR_SRC)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LINK = -L$(LIBFT_DIR) -lft

MLX_DIR = $(DIR_SRC)/minilibx_macos
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX_LINK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Combine all library settings
LIBS = $(LIBFT_LIB) $(MLX_LIB)
LIBS_INC = $(LIBFT_INC) $(MLX_INC)
LIBS_LINK = $(LIBFT_LINK) $(MLX_LINK)
LIBS_DIR = $(LIBFT_DIR) $(MLX_DIR)

# Main compilation rule
all: $(LIBS) $(NAME)

# Build the project executable
$(NAME): $(OBJ)
	@echo "$(COLOR_GREEN)Compiling $(NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBS_LINK) -o $(NAME)
	@echo "$(COLOR_GREEN)Compilation of $(NAME) completed successfully.$(COLOR_RESET)"

# Compile each library if not already present
$(LIBFT_LIB):
	@echo "$(COLOR_GREEN)Compiling libft...$(COLOR_RESET)"
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "$(COLOR_GREEN)Compiling MLX...$(COLOR_RESET)"
	@make -C $(MLX_DIR)

# Pattern rule for object files
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS_INC)

# Rule to clean up object files and libraries
clean:
	$(RM) $(OBJ)
	for dir in $(LIBS_DIR); do \
		echo "$(COLOR_GREEN)Cleaning $$dir...$(COLOR_RESET)"; \
		make -C $$dir clean; \
	done
	@echo "$(COLOR_GREEN)Clean-up completed.$(COLOR_RESET)"

# Rule to fully clean the project (includes removing the library)
fclean: clean
	$(RM) $(NAME)
	for dir in $(LIBS_DIR); do \
		echo "$(COLOR_GREEN)Full cleaning $$dir...$(COLOR_RESET)"; \
		if make -C $$dir fclean; then \
			echo "$(COLOR_GREEN)Full clean of $$dir completed.$(COLOR_RESET)"; \
		else \
			echo "$(COLOR_GREEN)fclean not available for $$dir, performing clean instead.$(COLOR_RESET)"; \
			make -C $$dir clean; \
		fi \
	done
	@echo "$(COLOR_GREEN)Full clean-up completed.$(COLOR_RESET)"

# Rule to recompile everything from scratch
re: fclean all

# Mark rules as phony (not file names)
.PHONY: all clean fclean re
