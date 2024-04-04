SRC=client.c server.c utils.c
OBJ=$(SRC:.c=.o)
BSRC=client_bonus.c server_bonus.c utils.c
BOBJ=$(BSRC:.c=.o)
LIBFT=make -C ./libft
CFLAGS=-Wall -Wextra -Werror

all: client server

client: client.o
	$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

server: server.o utils.o
	$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

bonus: client_bonus server_bonus

client_bonus: client_bonus.o
	$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

server_bonus: server_bonus.o utils.o
	$(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

clean:
	$(LIBFT) clean
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	$(LIBFT) fclean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re
