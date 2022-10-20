NAME = So_long
LIBFT = libft/libft.a
FLAGS =  -framework OpenGL -framework AppKit
SRC =   src/so_long.c               \
		src/map.c 					\
		src/player_movement.c       \
		src/utils.c                 \
        get_next_line/get_next_line.c         \
        get_next_line/get_next_line_utils.c   \

INC =   inc/so_long.h           \
        get_next_line/get_next_line.h     \


all: $(NAME)

$(NAME):
	make -C mlx
	gcc $(FLAGS) -o $(NAME) $(SRC) mlx/libmlx.a

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all