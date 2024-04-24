#include "minitalk.h"

// Função para lidar com os sinais recebidos
void	sig_handler(int sig)
{
	static unsigned char	byte; // Variável para armazenar um byte
	static unsigned char	ib; // Variável para contar os bits recebidos
	static char				*str; // Variável para armazenar a mensagem recebida

	// Se o sinal recebido for SIGUSR1 (sinal do cliente)
	if (sig == 10)
		byte = byte | 1 << ib; // Adiciona o bit recebido na posição correta
	ib++; // Incrementa o contador de bits
	if (ib == 8) // Se já tivermos recebido 8 bits (um byte completo)
	{
		str = ft_strjoinc(str, byte); // Adiciona o byte à mensagem
		if (byte == 0) // Se o byte for zero, significa que é o fim da mensagem
		{
			write (1, str, ft_strlen(str)); // Escreve a mensagem na tela
			write (1, "\n\n", 2); // Adiciona duas quebras de linha
			free (str); // Libera a memória da mensagem
			str = NULL; // Reseta o ponteiro da mensagem
		}
		byte = 0; // Reseta o byte
		ib = 0; // Reseta o contador de bits
	}
	// Se o sinal recebido for SIGINT (sinal de interrupção)
	if (sig == SIGINT)
	{
		free(str); // Libera a memória da mensagem
		exit(0); // Sai do programa
	}
}

// Função principal
int	main(void)
{
	pid_t	pid; // Variável para armazenar o ID do processo atual

	pid = getpid(); // Obtém o ID do processo atual
	ft_putnbr(pid); // Escreve o ID do processo atual na tela
	write (1, "\n", 1); // Escreve uma quebra de linha
	signal(SIGUSR1, sig_handler); // Configura o tratamento de sinal para SIGUSR1
	signal(SIGUSR2, sig_handler); // Configura o tratamento de sinal para SIGUSR2
	signal(2, sig_handler); // Configura o tratamento de sinal para SIGINT
	while (1)
	{
		sleep(1); // Dorme por 1 segundo
	}
	return (0); // Retorna 0 (sucesso)
}
