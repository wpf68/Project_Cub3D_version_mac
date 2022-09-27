# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 08:47:50 by pwolff            #+#    #+#              #
#    Updated: 2022/09/26 10:02:46 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS		= srcs/init_game.c  srcs/ft_close.c srcs/init_map.c srcs/error_msg.c srcs/main.c \
	srcs/print_map.c srcs/find_player.c srcs/draw_square.c srcs/check_files_map.c \
	srcs/check_nb_player.c srcs/count_char.c  srcs/init_player_position.c \
	srcs/init_var_player.c  srcs/movements.c srcs/draw_player.c srcs/ft_input.c \
	srcs/reprint_pos.c srcs/print_background.c srcs/init_legend.c


NAME        = cub_3D
OBJS_DIR	= objs/
PROJECT_H	= includes/cub3d.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
#MLXFLAGS = -framework OpenGL -framework AppKit
MLXFLAGS = -I /usr/X11/include -g -Lmlx_linux -lmlx_Linux -L /usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm
#MLXFLAGS = -I /usr/X11/include -I/usr/X11R6/include -L/usr/X11R6/lib -g -Lmlx_linux -lmlx_Linux -L /usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm


all: $(NAME)


#$(OBJS_DIR)%.o : %.c $(PROJECT_H)
#	@mkdir -p $(OBJS_DIR)
#	@mkdir -p $(OBJS_DIR)srcs
#	@$(CC) $(CC_FLAGS) -c $< -o $@
#	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

#$(NAME): $(OBJECTS_PREFIXED) maker
#	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) ./LIBFT/libft.a \
#	./MINILIBX/libmlx.a ${MLXFLAGS}
#	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)srcs
	$(CC) $(CC_FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) ./libft/libft.a \
	./mlx_linux/libmlx.a ${MLXFLAGS}
	printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"


maker:
	make -C ./libft
	make -C ./mlx_linux

clean:
	make clean -C ./libft
	make clean -C ./mlx_linux
	rm -rf $(OBJS_DIR)
	printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	make fclean -C ./libft
#	@make fclean -C ./mlx_linux
	rm -f $(NAME)
	printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

test: all
	./$(NAME) map.cub


.PHONY:		all clean fclean re maker test
