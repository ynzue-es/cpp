# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yannis <yannis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 15:37:23 by yannis            #+#    #+#              #
#    Updated: 2025/09/12 11:35:13 by yannis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP
SRC = src/main.cpp src/Bureaucrat.cpp
OBJ = $(SRC:src/%.cpp=obj/%.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CPP) $(CPPFLAGS) -Iincludes -c $< -o $@

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(OBJ:.o=.d)
	rm -rf obj
	
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all
