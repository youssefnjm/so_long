# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-01-03 10:45:05 by ynoujoum          #+#    #+#             #
#   Updated: 2025-01-03 10:45:05 by ynoujoum         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-01-03 10:45:05 by ynoujoum          #+#    #+#             #
#   Updated: 2025-01-03 10:45:05 by ynoujoum         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC_M =	so_long.c \
		utils_get_nex_line.c \
		utils_get_nex_line_utils.c \
		utils_map1.c \
		utils_map2.c \
		utils_mem.c \
		utils_split.c  \
		utils_window1.c \
		utils_window2.c \
		utils_window3.c \
		utils_putnbr.c

SRC_B = ./so_long_b/so_long_bonus.c \
		./so_long_b/utils_get_nex_line_bonus.c \
		./so_long_b/utils_get_nex_line_utils_bonus.c \
		./so_long_b/utils_map1_bonus.c \
		./so_long_b/utils_map2_bonus.c \
		./so_long_b/utils_mem_bonus.c \
		./so_long_b/utils_split_bonus.c  \
		./so_long_b/utils_window1_bonus.c \
		./so_long_b/utils_window2_bonus.c \
		./so_long_b/utils_window3_bonus.c \
		./so_long_b/utils_itoa_bonus.c \
		./so_long_b/utils_enemy_bonus.c

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M)
	$(COMPILER) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ_M) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B)
	$(COMPILER) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ_B) -o $(NAME_BONUS)

%.o : %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(OBJ_M): so_long.h
$(OBJ_B): ./so_long_b/so_long_bonus.h

clean:
	rm -rf $(OBJ_M) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

