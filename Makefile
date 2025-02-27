# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padan-pe <padan-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:32:41 by padan-pe          #+#    #+#              #
#    Updated: 2025/02/24 15:25:10 by padan-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftget_next_line.a
CC = cc 
C_FLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I. #directorio de cabeceras (dir actual)
SRC_FILES = get_next_line.c get_next_line_utils.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) # para evitar relink, solo hace cambios en la lib si algun archivo .o ha cambiado
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c #regla para compilar archivos .c en .o
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

clean: #regla para limpiar archivos .o
	rm -f $(OBJ_FILES)
fclean: #regla para limpiar todo incluyendo la lib
	rm -f $(NAME) $(OBJ_FILES)

re: fclean all #recompilar desde 0

.PHONY: all clean fclean re bonus