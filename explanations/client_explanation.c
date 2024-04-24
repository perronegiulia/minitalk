#include "minitalk.h"

// Função para enviar um caractere para o servidor
void	send(int pid, unsigned char c)
{
	int	i;
	int	sig;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1) // Verifica se o bit atual é 1
			sig = SIGUSR1; // Se sim, envia SIGUSR1
		else
			sig = SIGUSR2; // Se não, envia SIGUSR2
		kill(pid, sig); // Envia o sinal para o processo com o ID 'pid'
		usleep(100); // Espera um curto período de tempo
		i++; // Incrementa o contador de bits
	}
}

// Função para enviar uma string para o servidor
void	send_str(int pid, char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		send(pid, (unsigned char)str[i]); // Envia cada caractere da string
		i++; // Move para o próximo caractere
	}
	send(pid, 0); // Envia um byte zero para indicar o fim da string
}

// Função principal
int	main(int argc, char **argv)
{
	pid_t	pid; // Variável para armazenar o ID do processo servidor

	if (argc != 3) // Se o número de argumentos não for igual a 3
		return (0); // Sai do programa
	pid = ft_atoi(argv[1]); // Obtém o ID do processo servidor a partir do argumento
	send_str(pid, argv[2]); // Envia a mensagem para o processo servidor
	return (0); // Retorna 0 (sucesso)
}
