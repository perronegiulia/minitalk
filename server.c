#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig)
{
	static int i;

	if (sig == SIGUSR1)
	{
		write(1, "1", 1);
		i++;
	}
	else 
	{
		write(1, "0", 1);
		i++;
	}
	if (i % 8 == 0)
		write(1, "\n", 1);
}


int main(void)
{
	pid_t pid;

	pid = getpid();

	printf("%d\n", pid);

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	
	while(1)
	{
		sleep(1);
	}
	return(0);
}