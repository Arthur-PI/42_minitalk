# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 14:36:37 by apigeon           #+#    #+#              #
#    Updated: 2022/03/23 14:53:48 by apigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= cc
CFLAG	=	-Wall -Werror

### EXECUTABLE ###
SERVER	= server
CLIENT	= client

### INCLUDES ###
LIBFT	= libft
OBJ_DIR	= bin
HEADER	= incl
SRC_DIR	= src

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
all:	lib $(OBJ_DIR) $(SERVER) $(CLIENT)
	@echo "$(GREEN)Project successfully compiled$(NOC)"

lib:
	@echo "$(GREEN)Compiling libft$(NOC)"
	@$(MAKE) -C $(LIBFT)

$(SERVER):	$(SERVER_OBJS)
	@$(CC) $(CFLAGS) -L$(LIBFT) -lft $(SERVER_OBJS) -o $(SERVER)
	@echo "$(BLUE)Creating program file -> $(WHITE)$@... $(GREEN)[Done]$(NOC)"

$(CLIENT):	$(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -L$(LIBFT) -lft $(CLIENT_OBJS) -o $(CLIENT)
	@echo "$(BLUE)Creating program file -> $(WHITE)$@... $(GREEN)[Done]$(NOC)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(HEADER)  -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(NOC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(GREEN)Supressing object files$(NOC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT)

fclean:	clean
	@echo "$(GREEN)Supressing program files$(NOC)"
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) fclean -C $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re
