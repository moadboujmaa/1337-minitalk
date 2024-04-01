SRC=client.c server.c
OBJ=$(SRC:.c=.o)
LIBFT=make -C ./libft
CFLAGS=-Wall -Wextra -Werror

all: client server

client: client.o
	$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

server: server.o
	$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

clean:
	$(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(LIBFT) fclean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re