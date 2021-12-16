# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:41:21 by dabel-co          #+#    #+#              #
#    Updated: 2021/12/16 13:17:02 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
FLAGS = -Wall -Werror -Wextra
CC = cc

C = $(addprefix ./src/ft_, $(addsuffix .c, $(FILES)))

all: $(NAME)

$(NAME) :	check_libft
	@$(CC) $(FLAGS) ./src/ft_client.c ./Libft/libft.a -o client
	@$(CC) $(FLAGS) ./src/ft_server.c ./Libft/libft.a -o server
check_libft :
	@if test -d Libft; then ( cd Libft ; git pull --ff-only ) ; else git clone https://github.com/dabel-co/libft.git; fi
	@make extra -C ./Libft
clean:
	rm -f client
	rm -f server
fclean: clean
	make fclean -C ./Libft
re: clean all

.PHONY : all clean fclean re check_libft
