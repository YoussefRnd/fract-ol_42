NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -fr
MKDIR = mkdir -p
MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = lib/Libft
LIBFT = -L$(LIBFT_DIR) -lft

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(MKDIR) $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@echo "Building $@..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INC_DIR) $(LIBFT) $(MLX)
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