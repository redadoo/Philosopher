# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 19:13:32 by fborroto          #+#    #+#              #
#    Updated: 2024/04/13 17:52:59 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 			= philo

CC			  	= gcc 
FLAGS		  	= -pthread -lpthread -fsanitize=thread
RM			  	= rm -rf

OBJDIR        	= .objFiles

MAIN_SRC		= src/main src/monitor src/check
UTILS_SRC		= src/utils src/utils1 src/utils2


FILES 			= $(MAIN_SRC) $(UTILS_SRC)

SRC			  	= $(FILES:=.c)
OBJ			  	= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		  	= src/philosophers.h

NONE			="\033[0m"
GREEN			="\033[32m"
GRAY			="\033[2;37m"
CURSIVE			="\033[3m"
YELLOW			="\033[1;33"

.PHONY: all clean fclean re leaks

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo $(CURSIVE) $(GRAY) "      - Making object files..." $(NONE)
	@echo $(CURSIVE) $(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC)  $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

exe: all
	@echo "     - Executing $(NAME)..."
	@./$(NAME)  5 800 200 200 7
	@echo "     - Done -"

leaks: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind ./$(NAME) 4 800 200 200 7
	@echo "     - Done -"
leaks1: all
	@echo "     - Executing $(NAME) with leaks command..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 1 310 200 100
	@echo "     - Done -"
norm:
	@norminette $(SRCS)
	@norminette philosophers.h

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@$(RM) leaks.txt

fclean: clean
	@${RM} ${NAME}

re : fclean all