SRCS = main.c parser.c resolver.c tetrimino.c

OBJS = $(SRCS:.c=.o)
FILLIT_DIR = fillit_srcs/
LIBFT_DIR = libft_srcs/
NAME = fillit
FLAGS = -Wall -Wextra -Werror

.PHONY: clean

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	gcc $(FLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: fillit_srcs/%.c
	gcc -c $(FLAGS) $< -I $(FILLIT_DIR) -I $(LIBFT_DIR) -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)libft.a

re: fclean all
