# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdezaphi <kdezaphi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 08:47:42 by kdezaphi          #+#    #+#              #
#    Updated: 2016/06/09 15:31:29 by kdezaphi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_DIR = srcs/
SRC = 	lem_in.c ft_process_read.c ft_process_phase_1.c ft_check_phase_2.c \
		ft_process_phase_2.c ft_find_path.c ft_check_end.c ft_sup_path.c \
		ft_remove_non_end_path.c ft_set_len_path.c ft_set_ant_path.c \
		ft_print_ant.c ft_isint.c ft_freetab.c ft_freedim2.c

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = -Ilib/incs -Iincs

LIB_DIR = lib/
LIB_LNK = -L$(LIB_DIR) -lftprintf -lft -llst
LIB = $(addprefix $(LIB_DIR), libft.a libftprintf.a liblst.a)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@echo "\033[32mCreation de l'executable $@.\033[0m"
	@$(CC) $(CFLAGS) $(LIB_LNK) $(OBJ) -o $(NAME)

$(LIB):
	@make -C lib

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "\033[34mCreation du fichier objet $@.\033[0m"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C lib clean
	@echo "\033[35mSuppression des objets.\033[0m"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C lib fclean
	@echo "\033[31mSuppression du fichier $(NAME).\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
