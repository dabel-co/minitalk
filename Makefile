# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:41:21 by dabel-co          #+#    #+#              #
#    Updated: 2021/12/13 17:05:26 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
FLAGS = -Wall -Werror -Wextra
CC = cc
FILES =	minitalk \

C = $(addprefix ./src/ft_, $(addsuffix .c, $(FILES)))

all: $(NAME)

$(NAME) :	check_libft
	@$(CC) $(FLAGS) $(LINK) $(C) $(GNL) ./Libft/libft.a -o $(NAME)
check_libft :
	@if test -d Libft; then ( cd Libft ; git pull ) ; else git clone https://github.com/dabel-co/libft.git; fi
	@make extra -C ./Libft
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./Libft
re: clean all

.PHONY : all clean fclean re check_libft
