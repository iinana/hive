# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: injung <injung@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 09:24:53 by injung            #+#    #+#              #
#    Updated: 2024/01/26 08:56:59 by injung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs
INCLUDE = -Iincludes/

SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJECTS = $(SRCS:.c=.o)
OBJS = $(patsubst %.o, $(SRC_DIR)/%.o, $(OBJECTS))
TARGET = libft.a

all : $(TARGET)

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@

$(TARGET) : $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re : fclean all

.PHONY: all clean fclean re
