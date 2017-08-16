NAME = fdf

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

LFLAGS = -Llibft -lft -L$(MINILIB) -lmlx

DIR = srcs

LIB = lib

SRCS = main.c draw.c

SRC = $(addprefix $(DIR)/,$(SRCS))

OBJ = $(SRCS:.c=.o)

HEADERS = includes

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME) $(FRAMEWORK)

$(LIB): $(MINILIB)
	@make -C libft
	@make -C $(MINILIB)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADERS) -I $(MINILIB)

MINILIB: $(UNAME_S)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MINILIB = minilibx
endif
ifeq ($(UNAME_S),Darwin)
	FRAMEWORK = -framework OpenGl -framework AppKit
	UNAME_R := $(shell uname -r)
	ifneq ($(filter 15%, $(UNAME_R)),)
		MINILIB = minilibx_macos_el_capitan
	endif
	ifneq ($(filter 16%, $(UNAME_R)),)
		MINILIB = minilibx_macos_sierra
	endif
endif

clean:
	@rm -rf $(OBJ)
	@rm -f *.gch
	@make -C libft clean
	@make -C $(MINILIB) clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C $(MINILIB) clean

re: fclean all
