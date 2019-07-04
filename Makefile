# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edillenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 16:42:47 by edillenb          #+#    #+#              #
#    Updated: 2019/07/04 17:29:44 by edillenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT = libft/libft.a
EXECS = checker push_swap

SRC = $(addsuffix .c, checker push_swap algo quick_sort get_min_algo tools \
	  tools2)

OBJ = $(SRC:.c=.o)
OBJCHECKER = $(addsuffix .o, checker tools tools2)
OBJPUSHSWAP = $(addsuffix .o, push_swap algo quick_sort get_min_algo \
			  tools tools2)

GREEN = \033[01;32m
BLUE = \033[01;34m
RED = \033[01;31m
YELLOW = \033[01;33m
MAGENTA = \033[35m
BLACK = \033[30m
NOCOLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ) Makefile libft/Makefile libft/libft.h
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 "
	@echo "🔫                                                               🔫 $(MAGENTA)"
	@echo "🔫   [ auteur :  edillenb ]                                      🔫 $(BLUE)"
	@echo "🔫                                                               🔫 "
	@echo "🔫                          PUSH SWAP                            🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 $(BLACK)"
	make -C libft
	@echo "$(BLUE)⚡️ COMPILATION . . . . . . . . . . . . .$(YELLOW)"
	$(CC) $(CFLAGS) $(LIBFT) $(OBJCHECKER) -o checker
	$(CC) $(CFLAGS) $(LIBFT) $(OBJPUSHSWAP) -o $(NAME)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

clean:
	make clean -C libft
	@echo "$(BLUE)⚡️ SUPPR DES .O . . . . . . . . . .$(RED)"
	rm -f $(OBJ)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

fclean: clean
	make fclean -C libft
	@echo "$(BLUE)⚡️ SUPPR DES EXECUTABLES . . . . . .$(RED)"
	rm -f $(EXECS)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(BLACK)"

re: fclean all
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫  $(BLUE)ET C'EST REPARTI ! 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 "
	@echo "$(BLUE)⚡️ RELINK . . . . . . . . . . . . . . ."
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

.PHONY: all clean fclean re
