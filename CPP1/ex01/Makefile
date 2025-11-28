# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 15:23:51 by yannis            #+#    #+#              #
#    Updated: 2025/11/28 13:12:21 by ynzue-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
OBJ_DIR = obj/
INC_DIR = include/

SRCS =  src/Zombie.cpp \
		src/zombieHorde.cpp \
        src/main.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re