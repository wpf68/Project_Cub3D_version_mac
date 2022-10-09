# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 12:25:59 by pwolff            #+#    #+#              #
#    Updated: 2022/10/09 17:15:06 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# New version 221004

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRC		= srcs/init_game.c  srcs/ft_close.c srcs/init_map.c srcs/error_msg.c srcs/main.c \
	srcs/print_map.c srcs/find_player.c srcs/draw_square.c srcs/check_files_map.c \
	srcs/check_nb_player.c srcs/count_char.c  srcs/init_player_position.c \
	srcs/init_var_player.c  srcs/movements.c srcs/draw_player.c srcs/ft_input.c \
	srcs/reprint_pos.c srcs/print_background.c srcs/init_legend.c \
	srcs/init_cube.c srcs/anim_cub3D.c srcs/img_pix_put.c \
	srcs/anim_direction.c srcs/movements_mouse.c srcs/move_test.c srcs/ft_calc_texture.c \
	srcs/ft_init_text.c

NAME		= cub3D
OBJ			= $(SRC:.c=.o)
PROJECT_H	= includes/cub3d.h
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
OBJS_DIR	= objs/
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ))

ifeq ($(DESKTOP_SESSION), ubuntu)
MINILIBX = mlx_linux
MLXFLAGS = -I /usr/X11/include -g -Lmlx_linux -lmlx_Linux -L /usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm
else
MINILIBX = minilibx_mac
MLXFLAGS = -framework OpenGL -framework AppKit
endif

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)srcs
	$(CC) $(FLAGS) -I/usr/include -I$(MINILIBX) -O3 -c $< -o $@
	printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(FLAGS) ./libft/libft.a \
	./$(MINILIBX)/libmlx.a ${MLXFLAGS}
	printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

all: $(NAME)

test: all
	./$(NAME) map.cub 
	#valgrind ./$(NAME) map.cub 

maker:
	make -C ./libft
	make -C ./$(MINILIBX)

clean:
	@make clean -C ./libft
	@make clean -C ./$(MINILIBX)
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END) \n"

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END) \n"

re: fclean all 

bonus: all
	./$(NAME) map_star.cub 
	#valgrind ./$(NAME) map.cub 


.PHONY:		all clean fclean re maker test bonus
