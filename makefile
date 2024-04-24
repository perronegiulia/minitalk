# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 21:17:31 by lvichi            #+#    #+#              #
#    Updated: 2024/04/24 17:32:20 by gmaia-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniTalk

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SERVER_SRC = server.c utils.c
CLIENT_SRC = client.c utils.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_EXEC = server
CLIENT_EXEC = client

.PHONY: all clean fclean re

all: $(SERVER_EXEC) $(CLIENT_EXEC)

$(SERVER_EXEC): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -fr $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -fr $(SERVER_EXEC) $(CLIENT_EXEC)

re: fclean all