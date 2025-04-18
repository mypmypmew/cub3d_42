# **************************************************************************** #
#                              MAKEFILE CONFIG                                 #
# **************************************************************************** #

NAME = cube3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INC = -I$(MLX_DIR)/include

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

LIBS = -lglfw $(FRAMEWORKS)

SRCS = main.c
OBJS = $(SRCS:.c=.o)

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_INC) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_INC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
