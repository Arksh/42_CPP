# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 12:13:17 by cagonzal          #+#    #+#              #
#    Updated: 2022/12/16 15:52:49 by cagonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

# COLORS #
GREEN	= '\033[0;32m'
BLUE	= '\033[0;34m'
PURPLE	= '\033[0;35m'
CYAN	= '\033[0;36m'
RESET	= '\033[1;0m'

# VARIABLES #
NAME	= megaphone
INCLUDE	= -std=c++98
CC		= clang++
CFLAGS	= -Wall -Werror -Wextra

# PATHs #
SRC_PATH	= srcs
OBJ_PATH	= objects

# SOURCES #
SRC	= megaphone.cpp

# RULES #
all: $(NAME)

OBJ_NAME	= $(SRC:%.cpp=%.o)

SRCS	= $(addprefix $(SRC_PATH)/, $(SRC))

OBJS	= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

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
