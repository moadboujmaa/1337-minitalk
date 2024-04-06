SRC=client.c server.c utils.c
OBJ=$(SRC:.c=.o)
BSRC=client_bonus.c server_bonus.c utils.c
BOBJ=$(BSRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror
LIBFT_AR=./libft/libft.a

all: $(LIBFT_AR) client server 
	@echo " ██████   ██████ █████ ██████   █████ █████ ███████████   █████████   █████       █████   ████ "
	@echo "░░██████ ██████ ░░███ ░░██████ ░░███ ░░███ ░█░░░███░░░█  ███░░░░░███ ░░███       ░░███   ███░  "
	@echo " ░███░█████░███  ░███  ░███░███ ░███  ░███ ░   ░███  ░  ░███    ░███  ░███        ░███  ███    "
	@echo " ░███░░███ ░███  ░███  ░███░░███░███  ░███     ░███     ░███████████  ░███        ░███████     "
	@echo " ░███ ░░░  ░███  ░███  ░███ ░░██████  ░███     ░███     ░███░░░░░███  ░███        ░███░░███    "
	@echo " ░███      ░███  ░███  ░███  ░░█████  ░███     ░███     ░███    ░███  ░███      █ ░███ ░░███   "
	@echo " █████     █████ █████ █████  ░░█████ █████    █████    █████   █████ ███████████ █████ ░░████ "
	@echo "░░░░░     ░░░░░ ░░░░░ ░░░░░    ░░░░░ ░░░░░    ░░░░░    ░░░░░   ░░░░░ ░░░░░░░░░░░ ░░░░░   ░░░░  "

client: client.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

server: server.o utils.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

bonus: $(LIBFT_AR) client_bonus server_bonus 
	@echo " ██████   ██████ █████ ██████   █████ █████ ███████████   █████████   █████       █████   ████ "
	@echo "░░██████ ██████ ░░███ ░░██████ ░░███ ░░███ ░█░░░███░░░█  ███░░░░░███ ░░███       ░░███   ███░  "
	@echo " ░███░█████░███  ░███  ░███░███ ░███  ░███ ░   ░███  ░  ░███    ░███  ░███        ░███  ███    "
	@echo " ░███░░███ ░███  ░███  ░███░░███░███  ░███     ░███     ░███████████  ░███        ░███████     "
	@echo " ░███ ░░░  ░███  ░███  ░███ ░░██████  ░███     ░███     ░███░░░░░███  ░███        ░███░░███    "
	@echo " ░███      ░███  ░███  ░███  ░░█████  ░███     ░███     ░███    ░███  ░███      █ ░███ ░░███   "
	@echo " █████     █████ █████ █████  ░░█████ █████    █████    █████   █████ ███████████ █████ ░░████ "
	@echo "░░░░░     ░░░░░ ░░░░░ ░░░░░    ░░░░░ ░░░░░    ░░░░░    ░░░░░   ░░░░░ ░░░░░░░░░░░ ░░░░░   ░░░░  "

client_bonus: client_bonus.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

server_bonus: server_bonus.o utils.o
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_AR)

$(LIBFT_AR):
	@make -C ./libft

clean:
	@make -C ./libft clean
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@make -C ./libft fclean
	@rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re
