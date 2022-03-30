PATH_SRC = ./src/
PATH_VALIDATION = $(PATH_SRC)validation/
PATH_ERROR = $(PATH_SRC)error/
PATH_UTILS = $(PATH_SRC)utils/
PATH_GAME = $(PATH_SRC)game/
PATH_RENDER_DRAW = $(PATH_SRC)render_draw/
PATH_OBJ = ./obj/
PATH_LIBFT = ./libft/
PATH_INCLUDES = ./includes/
#BONUS
PATH_SRC_BONUS = ./src_bonus/
PATH_VALIDATION_BONUS = $(PATH_SRC_BONUS)validation/
PATH_ERROR_BONUS = $(PATH_SRC_BONUS)error/
PATH_UTILS_BONUS = $(PATH_SRC_BONUS)utils/
PATH_GAME_BONUS = $(PATH_SRC_BONUS)game/
PATH_RENDER_DRAW_BONUS = $(PATH_SRC_BONUS)render_draw/
PATH_OBJ_BONUS = ./obj_bonus/
PATH_INCLUDES_BONUS = ./includes_bonus/

LIBS = -L ./libft -lft -lmlx -lX11 -lXext -lm
SRC = $(PATH_SRC)free_struct.c \
	  $(addprefix $(PATH_ERROR), error.c) \
	  $(addprefix $(PATH_VALIDATION), args.c map.c color_character.c color_valid.c read_map_file.c texture.c wall.c) \
	  $(addprefix $(PATH_UTILS), utils.c rays_sides.c utils_mlx.c utils_start.c utils_map.c) \
	  $(addprefix $(PATH_GAME), actions.c) \
	  $(addprefix $(PATH_RENDER_DRAW), rays_utils.c draw_utils.c render_game.c rays.c projection3D.c)


#bonus
SRC_BONUS = $(PATH_SRC_BONUS)free_struct_bonus.c \
	  $(addprefix $(PATH_ERROR_BONUS), error_bonus.c) \
	  $(addprefix $(PATH_VALIDATION_BONUS), args_bonus.c map_bonus.c color_character_bonus.c color_valid_bonus.c read_map_file_bonus.c texture_bonus.c wall_bonus.c) \
	  $(addprefix $(PATH_UTILS_BONUS), utils_bonus.c rays_sides_bonus.c utils_mlx_bonus.c \
	  	utils_sprite_animated_bonus.c utils_start_bonus.c utils_map_bonus.c utils_sprites.c) \
	  $(addprefix $(PATH_GAME_BONUS), actions_bonus.c) \
	  $(addprefix $(PATH_RENDER_DRAW_BONUS), rays_utils_bonus.c draw_utils_bonus.c render_game_bonus.c rays_bonus.c projection3D_bonus.c sprites_bonus.c)

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))
#bonus
OBJS_BONUS = $(patsubst $(PATH_SRC_BONUS)%.c, $(PATH_OBJ_BONUS)%.o, $(SRC_BONUS))
NAME = cub3D
#bonus
NAME_BONUS = cub3D_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g -fsanitize=leak
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) -I $(PATH_INCLUDES) -o $(NAME) $(OBJS) $(PATH_SRC)cub3d.c $(LIBS)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)error
	@mkdir -p $(PATH_OBJ)validation
	@mkdir -p $(PATH_OBJ)utils
	@mkdir -p $(PATH_OBJ)render_draw
	@mkdir -p $(PATH_OBJ)game
	$(CC) $(CFLAGS) -I $(PATH_INCLUDES) -I. -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) -I $(PATH_INCLUDES_BONUS) -o $(NAME_BONUS) $(OBJS_BONUS) $(PATH_SRC_BONUS)cub3d_bonus.c $(LIBS)

$(PATH_OBJ_BONUS)%.o: $(PATH_SRC_BONUS)%.c
	@mkdir -p $(PATH_OBJ_BONUS)
	@mkdir -p $(PATH_OBJ_BONUS)error
	@mkdir -p $(PATH_OBJ_BONUS)validation
	@mkdir -p $(PATH_OBJ_BONUS)utils
	@mkdir -p $(PATH_OBJ_BONUS)render_draw
	@mkdir -p $(PATH_OBJ_BONUS)game
	$(CC) $(CFLAGS) -I $(PATH_INCLUDES_BONUS) -I. -c $< -o $@

test:
	@rm -rf test
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) -o check_test $(OBJS) ./tests/testing.c ./tests/unity/unity.c $(LIBS)

clean:
	$(RM) $(PATH_OBJ)
	make clean -C $(PATH_LIBFT)


fclean: clean
	$(RM) $(NAME)
	make fclean -C $(PATH_LIBFT)

re: fclean all

clean_bonus:
	$(RM) $(PATH_OBJ_BONUS)
	make clean -C $(PATH_LIBFT)


fclean_bonus: clean_bonus
	$(RM) $(NAME_BONUS)
	make fclean -C $(PATH_LIBFT)

re_bonus: fclean_bonus bonus

.PHONY: re all fclean clean

norminha:
	norminette $(PATH_SRC) $(PATH_INCLUDES) $(PATH_LIBFT)

add: fclean
	git add .
	git commit -m "testando a mlx"

push: add
	git push

valgrind_bonus:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./cub3D_bonus assets/bonus.cub

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./cub3D assets/mandatory.cub

