SRC_DIR	= src/

DEP_DIR	= includes/

OBJ_DIR	= bin/

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -I$(DEP_DIR)

SERVER	= server

CLIENT	= client

SERVER_SRC	= server.c \
			  utils.c

CLIENT_SRC	= client.c \
			  utils.c

SERVER_OBJS	= $(addprefix $(OBJ_DIR), $(SERVER_SRC:.c=.o))

CLIENT_OBJS	= $(addprefix $(OBJ_DIR), $(CLIENT_SRC:.c=.o))

all:		$(OBJ_DIR) $(SERVER) $(CLIENT)


$(SERVER):	$(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT):	$(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p bin/

clean:
	rm -rf bin/

fclean:	clean
	rm -f server client

re:		fclean all

.PHONY:	all clean fclean re