# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfuhrman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 12:25:59 by pwolff            #+#    #+#              #
#    Updated: 2022/10/16 15:02:32 by mfuhrman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# New version 221004

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRC		= srcs/init_game.c  srcs/ft_close.c srcs/error_msg.c srcs/main.c \
	srcs/print_map.c srcs/find_player.c srcs/draw_square.c srcs/check_files_map.c \
	srcs/check_nb_player.c srcs/count_char.c  srcs/init_player_position.c \
	srcs/init_var_player.c  srcs/movements.c srcs/draw_player.c srcs/ft_input.c \
	srcs/reprint_pos.c  srcs/init_legend.c \
	srcs/init_cube.c srcs/anim_cub3D.c srcs/img_pix_put.c \
	srcs/anim_direction.c srcs/movements_mouse.c srcs/move_test.c srcs/ft_calc_texture.c \
	srcs/ft_init_text.c srcs/anim_cub3D_2.c srcs/find_char.c srcs/check_border_map.c \
	srcs/check_char_map.c srcs/check_zeros.c srcs/check_parameters_map.c srcs/index_last_line.c \
	srcs/anim_cub3D_3.c srcs/init_parse.c srcs/parse_utils.c srcs/parse_text_and_color.c \
	srcs/parse_data_and_map.c

#srcs/print_background.c

SRC_BONUS		= srcs_bonus/ft_close.c srcs_bonus/main.c srcs_bonus/ft_input.c \
	srcs_bonus/anim_cub3D.c srcs_bonus/ft_calc_texture.c srcs_bonus/ft_init_text.c \
	srcs_bonus/check_border_map.c srcs_bonus/check_char_map.c srcs_bonus/anim_cub3D_3.c \
	\
	\
	srcs/anim_cub3D_2.c srcs/anim_direction.c \
	srcs/check_files_map.c srcs/check_nb_player.c srcs/check_parameters_map.c \
	srcs/check_zeros.c srcs/count_char.c srcs/draw_player.c srcs/draw_square.c \
	srcs/error_msg.c srcs/find_char.c srcs/find_player.c srcs/img_pix_put.c \
	srcs/index_last_line.c srcs/init_cube.c srcs/init_game.c srcs/init_legend.c \
	srcs/init_parse.c srcs/init_player_position.c \
	srcs/init_var_player.c srcs/move_test.c srcs/movements_mouse.c \
	srcs/movements.c srcs/parse_data_and_map.c srcs/parse_text_and_color.c \
	srcs/parse_utils.c srcs/print_map.c srcs/reprint_pos.c 

NAME		= cub3D
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
PROJECT_H	= includes/cub3d.h
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
OBJS_DIR	= objs/
OBJS_DIR_BONUS	= objs_bonus/
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ))
OBJECTS_PREFIXED_BONUS = $(addprefix $(OBJS_DIR_BONUS), $(OBJ_BONUS))

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

$(OBJS_DIR_BONUS)%.o : %.c $(PROJECT_H)
	mkdir -p $(OBJS_DIR_BONUS)
	mkdir -p $(OBJS_DIR_BONUS)srcs_bonus
	mkdir -p $(OBJS_DIR_BONUS)srcs
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
	@rm -rf $(OBJS_DIR_BONUS)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END) \n"

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END) \n"

re: fclean all 

bonus: $(OBJECTS_PREFIXED_BONUS) maker
	$(CC) -o $(NAME) $(OBJECTS_PREFIXED_BONUS) $(FLAGS) ./libft/libft.a \
	./$(MINILIBX)/libmlx.a ${MLXFLAGS}
	printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"
	./$(NAME) map_star.cub 
	#valgrind ./$(NAME) map.cub 


.PHONY:		all clean fclean re maker test bonus
