/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:16:08 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/13 18:25:04 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_handle_sigusr(int sig)
{
	if (sig == 30)
		printf("SIGUSR1\n");
	if (sig == 31)
		printf("SIGUSR2\n");

}
int main()
{
	struct	sigaction sa;
	
	sa.sa_handler = &ft_handle_sigusr;
	printf("Sever PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		printf("running\n");
		sleep(5);
	}
}
