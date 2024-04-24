/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:27:23 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/04/23 17:00:40 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static unsigned char	byte;
	static unsigned char	ib;
	static char				*str;

	if (sig == 10)
		byte = byte | 1 << ib;
	ib++;
	if (ib == 8)
	{
		str = ft_strjoinc(str, byte);
		if (byte == 0)
		{
			write (1, str, ft_strlen(str));
			write (1, "\n\n", 2);
			free (str);
			str = NULL;
		}
		byte = 0;
		ib = 0;
	}
	if (sig == SIGINT)
	{
		free(str);
		exit(0);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	signal(2, sig_handler);
	write (1, "\n", 1);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
