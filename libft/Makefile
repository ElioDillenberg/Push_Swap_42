# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edillenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 11:28:49 by edillenb          #+#    #+#              #
#    Updated: 2019/07/11 18:10:06 by edillenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_strnstr.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strdel.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_strsplit.c \
		  ft_itoa.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_putendl.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_display_file.c \
		  ft_lstrev.c \
		  ft_lstputstr.c \
		  ft_lstlen.c \
		  ft_putstrclr.c \
		  get_next_line_multi.c \
		  get_next_line.c \
		  ft_bitoa.c \
		  ft_free_stropt.c \
		  ft_itoa.c \
		  ft_hexatoa.c \
		  ft_lltoa.c \
		  ft_llutoa.c \
		  ft_octatoa.c \
		  ft_po.c \
		  ft_sqrt.c \
		  ft_str_add.c \
		  ft_swap.c \
		  ft_strjoinfr.c \
		  ft_str_up.c \
		  ft_printf.c \
		  convert.c \
		  flag.c \
		  float_a.c \
		  float_b.c \
		  cast_arg.c \
		  malloc_str.c \
		  fill_str.c \
		  ft_printf.c \
		  tools.c \
		  fill_float.c \
		  floatools.c \
		  color.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) Makefile libft.h ft_printf.h
	@gcc -Wall -Werror -Wextra -c $(SOURCES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
