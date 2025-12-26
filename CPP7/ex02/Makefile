# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yannis <yannis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 23:02:44 by yannis            #+#    #+#              #
#    Updated: 2025/12/26 23:03:00 by yannis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
OBJ_DIR = obj/
INC_DIR = includes/

SRCS = src/main.cpp
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