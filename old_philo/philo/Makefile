# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 12:22:16 by evocatur          #+#    #+#              #
#    Updated: 2023/11/12 17:08:22 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = $(MAIN_SRC)

MAIN_SRC = src/*.c

OBJ = *.o

CC = gcc -fsanitize=thread

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     - Compiling $(NAME)..." 
	@${CC} -pthread -lpthread $(FLAGS) $(OBJ) -o $(NAME)
	@echo "- Compiled -"
	@${RM} $(OBJ)
	
$(OBJ): $(SRCS)
	@echo "     - Making object files..." 
	@${CC} -pthread -c $(SRCS) $(FLAGS)

exe: all
	@echo "     - Executing $(NAME)..."
	@./$(NAME)  2 100 200 200
	@echo "     - Done -"

leaks: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --log-file="leak.txt" --leak-check=full --show-leak-kinds=all ./$(NAME) 1 400 200 200
	@echo "     - Done -"
leaks1: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --log-file="leak.txt" --leak-check=full --show-leak-kinds=all ./$(NAME) 1 310 200 100
	@echo "     - Done -"
norm:
	@norminette $(SRCS)
	@norminette philosophers.h

clean: 
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all