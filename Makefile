# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 14:57:32 by ajearuth          #+#    #+#              #
#    Updated: 2021/12/29 16:01:41 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Project sources and objs 

SRCS = 
SRCSD = srcs/
OBJSD = objs/
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))

#  Bonus sources and objs 

BONUS_NAME = so_long_bonus
BONUS_SRCS = 
BONUSD = bonus/
BONUSOD = $(BONUSD)objsb/
OBJSBONUS = $(addprefix $(BONUSOD), $(BONUS_SRCS:.c=.o))

# Libft sources and objs 

LIBSD = libs/
LIBFTD = $(addprefix $(LIBSD), libft/)
LIBFT = $(addprefix $(LIBFTD), libft.a)

# Minilibx sources and objs

MLXD = $(addprefix $(LIBSD), mlx_linux/)
MLX = $(addprefix $(MLXD), libmlx.a)
MLX_FLAGS = -lX11, -lXext 

DEPS = $(addprefix $(OBJD), $(SRCS:.c=.d))
LIBS = $(LIBFT) $(MLX)
LIBS_MAKE = make -C
CC = gcc -c -o
COMPIL = gcc -o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(LIBS) $(OBJS)
	$(COMPIL) $@ $(OBJS) $(MLX_FLAGS) $(LIBS)
	@echo "\033[0;32m\n          _         "
	@echo "   ______/ \-.   _  "
	@echo ".-/     (    o\_//    *~o~o~* OK *~o~o~* "
	@echo " |  ___  \_/\---'   "
	@echo "  |_||  |_||        "
	@echo "\033[0;35m                     Bonne correction !"


$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $< $(FLAGS) 

$(LIBS): $(LIBS_MAKE) $(LIBFTD) bonus
	$(LIBS_MAKE) $(MLXD) all

$(BONUSOD)%.o: $(BONUSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) $@ $< $(FLAGS)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(OBJSBONUS) $(LIBS) 
	$(COMPIL) $(BONUS_NAME) $(OBJSBONUS) $(LIBS)

clean:
	rm -rf $(OBJSD) $(BONUSOD)
	$(LIBS_MAKE) $(LIBFTD) clean
	$(LIBS_MAKE) $(MLXD) clean

fclean:	clean
	rm -rf $(NAME) $(BONUS_NAME)
	$(LIBS_MAKE) $(LIBFTD) fclean
	$(LIBS_MAKE) $(MLXD) clean

re: fclean all 

-include $(DEPS) 

.PHONY: all clean fclean re

