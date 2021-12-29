NAME = so_long

GCC = gcc
FLAGS = -Wall -Werror -Wextra 
MLX = libmlx.a
SRC = $(addprefix sources/, main.c so_long.c player_movement.c error_management.c ft_itoa.c utils.c)	\
	  $(addprefix sources/get_next_line/, get_next_line.c get_next_line_utils.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx/
	@$(GCC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@$(GCC) -c $< -o $@

clean:
	@make -C mlx clean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
