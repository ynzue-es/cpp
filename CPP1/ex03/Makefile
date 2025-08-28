# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yannis <yannis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 07:39:50 by yannis            #+#    #+#              #
#    Updated: 2025/08/28 07:44:16 by yannis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = human

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj/
INC_DIR = include/

SRCS = 	src/Weapon.class.cpp \
		src/HumanA.class.cpp \
		src/HumanB.class.cpp \
		src/main.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re