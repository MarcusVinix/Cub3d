PATH_SRC = ./src/
PATH_VALIDATION = $(PATH_SRC)validation/
PATH_ERROR = $(PATH_SRC)error/
PATH_UTILS = $(PATH_SRC)utils/
PATH_GAME = $(PATH_SRC)game/
PATH_RENDER_DRAW = $(PATH_SRC)render_draw/
PATH_OBJ = ./obj/
PATH_LIBFT = ./libft/
PATH_INCLUDES = ./includes/

LIBS = -L ./libft -lft -lmlx -lX11 -lXext -lm
SRC = $(PATH_SRC)free_struct.c \
	  $(addprefix $(PATH_ERROR), error.c) \
	  $(addprefix $(PATH_VALIDATION), args.c map.c color_character.c read_map_file.c texture.c wall.c) \
	  $(addprefix $(PATH_UTILS), utils.c sprites.c rays_sides.c) \
	  $(addprefix $(PATH_GAME), actions.c) \
	  $(addprefix $(PATH_RENDER_DRAW), draw_utils.c render_game.c rays.c projection3D.c)

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))
NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g -I $(PATH_INCLUDES) -fsanitize=leak
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PATH_SRC)cub3d.c $(LIBS)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)error
	@mkdir -p $(PATH_OBJ)validation
	@mkdir -p $(PATH_OBJ)utils
	@mkdir -p $(PATH_OBJ)render_draw
	@mkdir -p $(PATH_OBJ)game
	$(CC) $(CFLAGS) -I. -c $< -o $@

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

.PHONY: re all fclean clean

norminha:
	norminette $(PATH_SRC) $(PATH_INCLUDES) $(PATH_LIBFT)

add: fclean
	git add .
	git commit -m "testando a mlx"

push: add
	git push

valgrind:
	valgrind ./cub3D maps/valid_map.cub

