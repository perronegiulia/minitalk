/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:26:18 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/04/22 20:26:20 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, unsigned char c)
{
	int	i;
	int	sig;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		kill(pid, sig);
		usleep(100);
		i++;
	}
}

void	send_str(int pid, char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		send(pid, (unsigned char)str[i]);
		i++;
	}
	send(pid, 0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
