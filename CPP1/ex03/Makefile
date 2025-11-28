# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 07:39:50 by yannis            #+#    #+#              #
#    Updated: 2025/11/28 13:13:24 by ynzue-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = human

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj/
INC_DIR = include/

SRCS = 	src/Weapon.cpp \
		src/HumanA.cpp \
		src/HumanB.cpp \
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