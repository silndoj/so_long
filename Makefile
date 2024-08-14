NAME				= 	so_long

CC					=		cc
CFLAGS			=   -Wextra -Wall -Werror 
SRCS_MAIN		= 	src/background.c	\
								src/error.c				\
								src/main.c				
OBJ 				=		tools/obj
LIBFT 			=		tools/lib/libft/libft.a
OBJ_MAIN		=		$(SRCS_MAIN:src/%.c=$(OBJ)/%.o)

all:						$(NAME)

$(LIBFT):
				@cd tools/lib/libft && make

$(NAME):MLX42 $(LIBFT) $(OBJ_MAIN)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_MAIN) -L./MLX42/build/ -lmlx42 -Iinclude -lglfw -L./tools/lib/libft -lft

MLX42:
				@git clone https://github.com/codam-coding-college/MLX42.git
				@cd MLX42 && cmake -B build && cmake --build build -j4

mlx:		MLX42

$(OBJ)/%.o:			src/%.c
					@cd tools
					@mkdir -p $(OBJ)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@cd tools/lib/libft && make clean
			@rm -rf $(OBJ)/*


fclean: 			clean
			@rm -rf $(NAME)
			@rm -rf $(OBJ)
			@cd tools/lib/libft && make fclean


re:			fclean mlx all

.PHONY:		all clean fclean re
