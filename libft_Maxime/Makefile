# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 12:35:50 by mfuhrman          #+#    #+#              #
#    Updated: 2022/10/04 13:49:05 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_bzero.c  ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	  ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	 get_next_line.c get_next_line_utils.c ft_print_hex.c ft_print_opt.c ft_print_unsigned.c \
	ft_print_void.c ft_printf.c 
OBJ = $(SRC:.c=.o)
NAME = libft.a
RM = rm -f 

GREEN = '\033[0;32m'
RED = '\033[0;31m'
NONE = '\033[0m'
GRAY = '\033[2;37m'
CURSIVE = '\033[3m'

all : $(NAME)	

$(NAME) : $(OBJ)
		@echo $(CURSIVE)$(GRAY) " -Making Libft..."$(NONE)
		ar -rcs $(NAME) $(OBJ)
		$(RM) $(OBJ)
		@echo "$(NAME) $(GREEN)$(NAME) was created !$(NONE)"

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	@echo "$(NAME) $(RED)$(NAME) was deleted !$(NONE)"

re : fclean $(NAME)

.PHONY : all clean fclean re



