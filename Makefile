NAME				= 	so_long

CC					=		cc
CFLAGS				=   -g -Wextra -Wall -Werror 

SRCS_MAIN			= 	src/free_game.c						\
								src/error.c					\
								src/main.c					\
								src/map.c 					\
								src/map_pars.c				\
								src/map_pars_utils.c		\
								src/gui_2d.c 				\
								src/key_hook.c		

LIBFT 				=	tools/lib/libft/libft.a

OBJ 				=	tools/obj
OBJ_MAIN			=	$(SRCS_MAIN:src/%.c=$(OBJ)/%.o)

all:						$(NAME)

$(LIBFT):
				@cd tools/lib/libft && make -s

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
			@rm -rf $(OBJ)/*
			@cd tools/lib/libft && make clean -s


fclean: 			clean
			@rm -rf $(NAME)
			@rm -rf $(OBJ)
			@cd tools/lib/libft && make fclean -s


re:			fclean all

.PHONY:		all clean fclean re
