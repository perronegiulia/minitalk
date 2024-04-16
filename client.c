#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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

int main(int argc, char **argv)
{
	pid_t pid;
	char c;
	int i;
	int mask;

	mask = 128;
	i = 0;
	c = 'b';
	pid = ft_atoi(argv[1]);

	while(i < 8)
	{
		if (c & mask)
			kill(pid, 10);
		else 
			kill(pid, 12);
		sleep(1);
		i++;
		printf ("mask: %d\n", mask);
		mask = mask >> 1;
	}
//	kill(pid, 10);
//	sleep(2);
//	kill(pid, 12);
}