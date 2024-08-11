NAME		:= so_long

LIBFT		:= ./lib/libft
MLX42		:= ./lib/MLX42

CC			=	cc
CFLAGS		=   -g -Wextra -Wall -Werror 

RM			=	rm -rf

INCLUDES	=	-I ./include -I $(MLX42)/include

SRCS_MAIN	:= $(shell find ./src -iname "*.c")
SRCS_EXTRA	:= $(shell find ./src/extra -iname "*.c")

LIBS		:= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBS		=	-lglfw $(MLX42)/build/libmlx42.a $(LIBFT)/libft.a

OBJ_MAIN		=	$(SRCS_MAIN:.c=.o)
OBJ_EXTRA		=	$(SRCS_EXTRA:.c=.o)

all: LIBFT $(NAME)

MLX42:
	@cmake $(MLX42) -B $(MLX42)/build && make -C $(MLX42)/build -j4

LIBFT:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(NAME): $(OBJ_MAIN) $(OBJ_EXTRA)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJ_MAIN) -o $(NAME) $(INCLUDES)


clean:	
			@make -C $(LIBFT) clean --silent
			@rm -rf $(OBJ_MAIN) $(OBJ_EXTRA)


fclean: 	clean
			@make -C $(LIBFT) fclean --silent
			@rm -rf $(NAME)


re:			fclean all

.PHONY:		all clean fclean re mlx42
