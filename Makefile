NAME = woody_woodpacker

SRC = src/main.c src/analyse.c

FLAGS = gcc -g3 -Wall -Werror -Wextra -I includes -o

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/ fclean && make -C libft/ all
	$(FLAGS) $(NAME) $(SRC) libft/libft.a

clean:
	make -C libft/ clean

fclean:
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
