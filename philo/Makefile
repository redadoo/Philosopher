# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 12:22:16 by evocatur          #+#    #+#              #
#    Updated: 2023/09/11 20:37:27 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRCS = $(MAIN_SRC)

MAIN_SRC = src/*.c

OBJ = *.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     - Compiling $(NAME)..." 
	@${CC} -pthread $(FLAGS) $(OBJ) -o $(NAME)
	@echo "- Compiled -"
	@${RM} $(OBJ)
	
$(OBJ): $(SRCS)
	@echo "     - Making object files..." 
	@${CC} -pthread -c $(SRCS)

exe: all
	@echo "     - Executing $(NAME)..."
	@./$(NAME)  3 300 200 100 17
	@echo "     - Done -"

leaks: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 5 800 200 200
	@echo "     - Done -"

clean: 
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}