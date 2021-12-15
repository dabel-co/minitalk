/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:16:08 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/15 19:06:15 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int counter = 0;

static void	ft_recive_char(int bit)
{
	char x;

	if (counter == 0)
		x = 0;
	x += bit << counter;
	counter++;
	if (counter == 8)
	{
		write(1, &x, 1);
		if (x == '\0')
			write(1, "\n", 1); 
		counter = 0;
	}
}

static	void	ft_handle_sigusr(int sig)
{
	if (sig == 30)
		ft_recive_char(0);
	if (sig == 31)
		ft_recive_char(1);
}

int main()
{
	struct	sigaction sa;
	
	sa.sa_handler = &ft_handle_sigusr;
	//fix libft, change to my own printf
	printf("Sever PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{

	}
}
