# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 12:13:17 by cagonzal          #+#    #+#              #
#    Updated: 2023/01/09 15:28:39 by cagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #
NC			=	'\033[0m'
GREEN		=	'\033[0;32m'
RED			=	'\033[0;91m'
BLUE		=	'\033[0;94m'
MAGENTA		=	'\033[0;95m'
CYAN		=	'\033[0;96m'
WHITE		=	'\033[0;97m'
LRED		=	'\033[1;31m'
LGREEN		=	'\033[1;32m'
YELLOW		=	'\033[1;33m'
LBLUE		=	'\033[1;34m'
GRAY		=	'\033[2;37m'
CURSIVE		=	'\033[3m'
TITLE		=	'\033[38;5;33m'

# VARIABLES #
NAME		=	floatPoint
CC			=	clang++
INCLUDE		=	-std=c++98
CFLAGS		=	-Wall -Werror -Wextra

# PATHs #
SRC_PATH	=	src# Source location
OBJ_PATH	=	obj# Bin location

# SOURCES #
SRC			=	bsp.cpp main.cpp Fixed.cpp Point.cpp

# RULES #
all: $(NAME)

OBJ_NAME = $(SRC:%.cpp=%.o)

SRCS = $(addprefix $(SRC_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "- Compiling $(NAME)..." $(NC)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)
	@echo "Project "$(TITLE)"$(NAME) "$(GREEN)"compiled\n"$(NC)

##RULES
$(MAKE): make

clean:
	@echo $(CURSIVE)$(GRAY)"- Removing object files..." $(NC)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo $(CURSIVE)$(GRAY)"- Removing $(NAME)..." $(NC)
	@rm -rf $(NAME)
	@echo "Project "$(TITLE)"$(NAME) "$(GREEN)"cleaned\n"$(NC)

re: fclean all

PHONY.: all clean fclean re norminette
