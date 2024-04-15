# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: injung <injung@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 21:16:01 by injung            #+#    #+#              #
#    Updated: 2024/01/31 15:54:19 by injung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs
INCLUDE = -Iincludes/

SRCS = main.c file_map.c ft_func.c square.c std_map.c
OBJECTS = $(SRCS:.c=.o)
OBJS = $(patsubst %.o, $(SRC_DIR)/%.o, $(OBJECTS))
TARGET = bsq

all: $(TARGET)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re : fclean all

.PHONY: all clean fclean re
