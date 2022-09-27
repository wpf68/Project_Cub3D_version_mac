BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRC		= srcs/init_game.c  srcs/ft_close.c srcs/init_map.c srcs/error_msg.c srcs/main.c \
	srcs/print_map.c srcs/find_player.c srcs/draw_square.c srcs/check_files_map.c \
	srcs/check_nb_player.c srcs/count_char.c  srcs/init_player_position.c \
	srcs/init_var_player.c  srcs/movements.c srcs/draw_player.c srcs/ft_input.c \
	srcs/reprint_pos.c srcs/print_background.c srcs/init_legend.c

#  *********************************************************
#  *******************   Version Mac  **********************
#  *********************************************************

NAME		= cub3D


OBJ		= $(SRC:.c=.o)
PROJECT_H	= includes/cub3d.h
CC		= gcc
FLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) $(OBJ) maker
	$(CC) $(FLAGS) -lmlx ${MLXFLAGS} $(SRC) -o $(NAME) ./libft/libft.a

%.o: %.c
	$(CC) -c $(FLAGS) -Imlx $< -o $@

maker:
	make -C ./libft

run: all
	./$(NAME)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all 

test: all
	./$(NAME) map.cub

.PHONY:		all clean fclean re test

