# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edillenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 16:42:47 by edillenb          #+#    #+#              #
#    Updated: 2019/07/15 17:54:30 by edillenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT = libft/libft.a
EXECS = checker push_swap

SRC = $(addsuffix .c, checker push_swap algo tools tools2 final_instructions \
	  checks exe_instructions get_instructions)

OBJ = $(SRC:.c=.o)
OBJCHECKER = $(addsuffix .o, checker tools tools2 final_instructions checks \
			 get_instructions)
OBJPUSHSWAP = $(addsuffix .o, push_swap algo tools tools2 final_instructions \
			  checks exe_instructions get_instructions)

GREEN = \033[01;32m
BLUE = \033[01;34m
RED = \033[01;31m
YELLOW = \033[01;33m
MAGENTA = \033[35m
BLACK = \033[30m
NOCOLOR = \033[0m

all: $(NAME) checker

$(NAME): $(OBJ) Makefile
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 "
	@echo "🔫                                                               🔫 $(MAGENTA)"
	@echo "🔫   [ auteur :  edillenb ]                                      🔫 $(BLUE)"
	@echo "🔫                                                               🔫 "
	@echo "🔫                          PUSH_SWAP                            🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 $(BLACK)"
	make -C libft
	@echo "$(BLUE)⚡️ COMPILATION DE PUSH_SWAP. . . . . . . . .$(YELLOW)"
	$(CC) $(CFLAGS) $(LIBFT) $(OBJPUSHSWAP) -o $(NAME)
	@echo "$(GREEN)TOUT EST ---------------------------> OK$(NOCOLOR)"

checker: $(OBJ) Makefile
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 "
	@echo "🔫                                                               🔫 $(MAGENTA)"
	@echo "🔫   [ auteur :  edillenb ]                                      🔫 $(BLUE)"
	@echo "🔫                                                               🔫 "
	@echo "🔫                          CHECKER                              🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫                                                               🔫 "
	@echo "🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 🔫 $(BLACK)"
	make -C libft
	@echo "$(BLUE)⚡️ COMPILATION DE CHECKER. . . . . . . . . .$(YELLOW)"
	$(CC) $(CFLAGS) $(LIBFT) $(OBJCHECKER) -o checker
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
