# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: injung <injung@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:26:04 by injung            #+#    #+#              #
#    Updated: 2024/01/25 16:53:56 by injung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET= ft_display_file

all: $(TARGET)

$(TARGET) : main.c
	cc -Wall -Wextra -Werror $< -o $(TARGET)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
