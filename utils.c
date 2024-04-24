/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaia-pe <gmaia-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:25:28 by gmaia-pe          #+#    #+#             */
/*   Updated: 2024/04/24 16:30:49 by gmaia-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	p;
	int	nb;

	i = 0;
	p = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		p = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str [i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (p * nb);
}

void	ft_putnbr(int num)
{
	unsigned int	n;

	n = num;
	if (num < 0)
	{
		n = -num;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

char	*ft_strjoinc(char *str, char c)
{
	char	*res;
	int		i;

	if (!str)
	{
		str = (char *)malloc(1);
		*str = 0;
	}
	res = (char *)malloc(ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = 0;
	free (str);
	return (res);
}
