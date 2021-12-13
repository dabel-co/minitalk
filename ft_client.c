/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:53:41 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/13 19:22:31 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_convert_string(char *str, int pid)
{
}

int	main(int argc, char **argv)
{
	//add some protection
	char x = '}';
	int i = 0;
	while (i < 8)
	{
		int q = (x << i) & 0x80;
		printf("%d\n", q);

		i++;
	}
	//ft_convert_string(argv[2], ft_atoi(argv[1]));
		
}
