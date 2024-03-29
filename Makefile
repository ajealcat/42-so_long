
NAME = so_long

# Project sources and objs 

SRCS = main.c get_next_line.c get_next_line_utils.c map_checker.c map_reader.c \
	init_map.c set_up_map.c moove_player.c close_nicely.c
SRCSD = srcs/
OBJSD = objs/
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))

#  Bonus sources and objs 

BONUS_NAME = so_long_bonus
BONUS_SRCS = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c map_checker_bonus.c \
	map_reader_bonus.c init_map_bonus.c set_up_map_bonus.c \
	moove_player_bonus.c close_nicely_bonus.c add_slime_bonus.c moove_player_utils_bonus.c \
	add_slime_utils_bonus.c
BONUSD = bonus/
BONUSOD = $(BONUSD)objsb/
OBJSBONUS = $(addprefix $(BONUSOD), $(BONUS_SRCS:.c=.o))

# Libft sources and objs 

LIBSD = libs/
LIBFTD = $(addprefix $(LIBSD), libft/)
LIBFT = $(addprefix $(LIBFTD), libft.a)

# Minilibx sources and objs

MLXD = $(addprefix $(LIBSD), mlx_linux/)
MLX = $(addprefix $(MLXD), libmlx_Linux.a)
MLX_FLAGS = -lX11 -lXext 

DEPS = $(addprefix $(OBJD), $(SRCS:.c=.d))
LIBS = $(LIBFT) $(MLX)
LIBS_MAKE = make -C
CC = clang -c -o
COMPIL = clang
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):	$(LIBS) $(OBJS)
	$(COMPIL) $(FLAGS) $(OBJS) $(MLX_FLAGS) $(LIBS) -o $@
	@echo "\033[0;32m\n          _         "
	@echo "   ______/ \-.   _  "
	@echo ".-/     (    o\_//    *~o~o~* OK *~o~o~* "
	@echo " |  ___  \_/\---'   "
	@echo "  |_||  |_||        "
	@echo "\033[0;35m                     Bonne correction !"


$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $(FLAGS) -I $(LIBFTD) -I $(MLXD) -MMD $<

$(LIBS):
	$(LIBS_MAKE) $(MLXD) all
	$(LIBS_MAKE) $(LIBFTD) bonus

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(LIBS) $(OBJSBONUS) 
	$(COMPIL) $(OBJSBONUS) $(MLX_FLAGS) $(LIBS) -o $@

$(BONUSOD)%.o: $(BONUSD)%.c
	mkdir -p $(BONUSOD)
	$(CC) $@ $(FLAGS) -I $(LIBFTD) -I $(MLXD) -MMD $< 

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

.PHONY: all bonus clean fclean re

