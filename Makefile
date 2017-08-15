NAME = fdf

FLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

LFLAGS = -Llibft -lft -Lminilibx_macos_sierra -lmlx

SRC = main.c

HEADERS = libft/includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@make -C libft
	@make -C minilibx_macos_sierra
	@gcc $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ):
	@gcc $(FLAGS) -c $(SRC) -I $(HEADERS) -I minilibx_macos_sierra

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
