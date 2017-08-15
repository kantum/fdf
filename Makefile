NAME = fdf

CC = clang

FLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

LFLAGS = -Llibft -lft -Lminilibx_macos_sierra -lmlx

FRAMEWORK = -framework OpenGl -framework AppKit

SRCS = srcs/

SRC = main.c

HEADERS = includes

LHEADERS = libft/includes

LIB = lib

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME) $(FRAMEWORK)

$(LIB):
	make -C libft
	make -C minilibx_macos_sierra

$(OBJ):$(SRCS)$(SRC)
	gcc $(FLAGS) -c $(SRCS)$(SRC) -I $(HEADERS) -I minilibx_macos_sierra

clean:
	@rm -rf $(OBJ)
	@rm -f *.gch
	@make -C libft clean
	@make -C minilibx_macos_sierra clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C minilibx_macos_sierra clean

re: fclean all
