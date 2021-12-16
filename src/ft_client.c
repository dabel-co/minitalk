/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:53:41 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/16 13:12:48 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(char x, int pid)
{
	int	i;
	
	i = 0;
	while (i < 8)
	{
		if (((x >> i) & 0x01) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	int pid;
	int i;

	if (argc != 3 || !argv[1] || !argv[2] || ft_strlen(argv[2]) == 0)
		return (0);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_send_char(argv[2][i], pid);
		i++;
	}
	ft_send_char('\0', pid);
}
