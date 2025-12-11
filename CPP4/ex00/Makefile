# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 09:31:14 by yannis            #+#    #+#              #
#    Updated: 2025/12/11 10:51:39 by ynzue-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMP -MD
OBJ_DIR = obj/
INC_DIR = include/

SRCS =  src/Animal.cpp \
        src/Cat.cpp \
        src/Dog.cpp \
		src/WrongAnimal.cpp \
		src/WrongCat.cpp \
        src/main.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp $(INC_DIR)/Animal.hpp $(INC_DIR)/Cat.hpp $(INC_DIR)/Dog.hpp $(INC_DIR)/WrongAnimal.hpp $(INC_DIR)/WrongCat.hpp 
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