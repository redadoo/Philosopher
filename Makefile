# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 19:13:32 by fborroto          #+#    #+#              #
#    Updated: 2023/11/14 12:10:55 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS = $(MAIN_SRC)

MAIN_SRC = src/*.c

OBJ = *.o

CC = gcc #-fsanitize=thread

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     - Compiling $(NAME)..." 
	@${CC} -pthread -lpthread $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "- Compiled -"
	@${RM} $(OBJ)
	
$(OBJ): $(SRCS)
	@echo "     - Making object files..." 
	@${CC} -pthread -c $(SRCS)

exe: all
	@echo "     - Executing $(NAME)..."
	@./$(NAME)  3 800 200 200 5
	@echo "     - Done -"

leaks: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 5 800 200 200 7
	@echo "     - Done -"
leaks1: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 1 310 200 100
	@echo "     - Done -"
norm:
	@norminette $(SRCS)
	@norminette philosophers.h

clean: 
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}