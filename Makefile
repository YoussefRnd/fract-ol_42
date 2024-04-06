NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -fr
MKDIR = mkdir -p
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/yboumlak/goinfre/homebrew/Cellar/glfw/3.4/lib"

LIBFT_DIR = lib/Libft
LIBFT = -L$(LIBFT_DIR) -lft

MLX_DIR = MLX42
MLX = $(MLX_DIR)/build/libmlx42.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

HEADERS = -I ./$(SRC_DIR) -I $(LIBMLX)/include

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(MKDIR) $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADERS) $(LIBFT) $(MLX) $(MLX_FLAGS)
	@echo "$@ is ready!"

clean:
	@echo "Cleaning object files..."
	@make -s clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Cleaning $(NAME)..."
	@make -s fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re