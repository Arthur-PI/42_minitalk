# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:36:37 by apigeon           #+#    #+#              #
#    Updated: 2022/03/28 14:53:41 by apigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= cc
CFLAG	= -Wall -Werror -Wextra

### EXECUTABLE ###
SERVER	= server
CLIENT	= client

### INCLUDES ###
SRC_DIR		= src
OBJ_DIR		= bin
HEADER		= incl
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

### SOURCE FILES ###
SERVER_SRC	= server.c
CLIENT_SRC	= client.c

### OBJECTS ###
SERVER_OBJS	= $(addprefix $(OBJ_DIR)/, $(SERVER_SRC:.c=.o))
CLIENT_OBJS	= $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC:.c=.o))

### COLORS ###
NOC		= \033[0m
BLACK	= \033[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

### RULES ###
all:	$(LIBFT) $(OBJ_DIR) $(SERVER) $(CLIENT)
	@echo "$(GREEN)Project successfully compiled$(NOC)"

$(LIBFT):
	@echo "$(GREEN)Compiling libft$(NOC)"
	@$(MAKE) -C $(LIBFT_DIR)

$(SERVER):	$(SERVER_OBJS)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(SERVER_OBJS) -o $(SERVER)
	@echo "$(BLUE)Creating program file -> $(WHITE)$@... $(GREEN)[Done]$(NOC)"

$(CLIENT):	$(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(CLIENT_OBJS) -o $(CLIENT)
	@echo "$(BLUE)Creating program file -> $(WHITE)$@... $(GREEN)[Done]$(NOC)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(HEADER) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(NOC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Supressing object files$(NOC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean:	clean
	@echo "$(RED)Supressing program files$(NOC)"
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re:		fclean all

.PHONY:	all clean fclean re
