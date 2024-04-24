NAME = fractol
BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -g 
RM = rm -fr
MKDIR = mkdir -p
MLX_FLAGS_MAC = -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/yboumlak/goinfre/homebrew/Cellar/glfw/3.4/lib"
MLX_FLAGS_LINUX = -ldl -lglfw -pthread -lm

LIBFT_DIR = lib/Libft
LIBFT = -L$(LIBFT_DIR) -lft

MLX_DIR = lib/MLX42
MLX = $(MLX_DIR)/build/libmlx42.a

SRC_DIR = src/mandatory
SRC_BONUS_DIR = src/bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus
INC_DIR = inc

HEADERS = -I $(INC_DIR) -I $(MLX_DIR)/include

SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS_BONUS = $(wildcard $(SRC_BONUS_DIR)/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	@$(MKDIR) $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS_MAC)
	@echo "$@ is ready!"

bonus: $(BONUS)

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(INC_DIR)/fractol_bonus.h
	@$(MKDIR) $(OBJ_BONUS_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(BONUS): $(OBJS_BONUS)
	@make -s -C $(LIBFT_DIR)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS_MAC)
	@echo "$@ is ready!"

mlx:
	@echo "Building MLX42..."
	@git submodule init
	@git submodule update
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

clean:
	@echo "Cleaning object files..."
	@make -s clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	@echo "Cleaning $(NAME)..."
	@make -s fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus