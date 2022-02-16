PATH_SRC = ./src/
PATH_VALIDATION = $(PATH_SRC)validation/
PATH_ERROR = $(PATH_SRC)error/
PATH_OBJ = ./obj/
PATH_LIBFT = ./libft/
PATH_INCLUDES = ./includes/

LIBS = -L ./libft -lft -lmlx -lX11 -lXext
SRC = $(PATH_SRC)free_struct.c \
	  $(addprefix $(PATH_ERROR), error.c) \
	  $(addprefix $(PATH_VALIDATION), args.c map.c color_character.c read_map_file.c texture.c wall.c) 

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))
NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -I $(PATH_INCLUDES)  #-fsanitize=address
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(PATH_SRC)cub3d.c $(OBJS) $(LIBS)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)error
	@mkdir -p $(PATH_OBJ)validation
	$(CC) $(CFLAGS) -I. -c $< -o $@

test:
	@rm -rf test
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ./tests/testing.c ./tests/unity/unity.c -o check_test

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
	git commit -m "configurando o projeto para poder usar mlx"

push: add
	git push

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./cub3d maps/valid_map.cub

