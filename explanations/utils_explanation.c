#include "minitalk.h"

// Função para calcular o comprimento de uma string
size_t	ft_strlen(const char *str)
{
	size_t	i; // Variável para contar os caracteres

	i = 0; // Inicializa o contador
	while (str[i]) // Enquanto houver caracteres na string
		i++; // Incrementa o contador
	return (i); // Retorna o comprimento da string
}




// Função para converter uma string em um número inteiro
int	ft_atoi(const char *str)
{
	int	i; // Variável para iterar sobre os caracteres da string
	int	p; // Variável para armazenar o sinal do número (+ ou -)
	int	nb; // Variável para armazenar o número convertido

	i = 0; // Inicializa o índice
	p = 1; // Inicializa o sinal como positivo
	nb = 0; // Inicializa o número como zero
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r') // Ignora espaços em branco no início da string
		i++; // Incrementa o índice
	if (str[i] == '-') // Verifica se o número é negativo
		p = -1; // Se sim, define o sinal como negativo
	if (str[i] == '-' || str[i] == '+') // Ignora o sinal na string
		i++; // Move para o próximo caractere
	while (str[i] >= '0' && str [i] <= '9') // Converte os caracteres numéricos para inteiro
	{
		nb = nb * 10 + (str[i] - '0'); // Converte o caractere para o inteiro correspondente
		i++; // Move para o próximo caractere
	}
	return (p * nb); // Retorna o número convertido com o sinal correto
}




// Função para imprimir um número inteiro na tela
void	ft_putnbr(int num)
{
	unsigned int	n; // Variável para armazenar o número positivo

	n = num; // Converte o número para positivo
	if (num < 0) // Se o número for negativo
	{
		n = -num; // Converte para positivo
		write(1, "-", 1); // Escreve o sinal negativo na tela
	}
	if (n >= 10) // Se o número tiver mais de um dígito
		ft_putnbr(n / 10); // Chama recursivamente a função para os dígitos restantes
	write(1, &"0123456789"[n % 10], 1); // Escreve o último dígito na tela
}




// Função para juntar uma string com um caractere
char	*ft_strjoinc(char *str, char c)
{
	char	*res; // Ponteiro para a string resultante
	int		i; // Variável para iterar sobre os caracteres da string

	// Se a string de entrada for nula
	if (!str)
	{
		// Alocamos memória para uma string vazia com tamanho 1
		str = (char *)malloc(1);
		*str = 0; // Definimos o primeiro caractere como '\0'
	}
	// Alocamos memória para a nova string resultante, incluindo o caractere extra e o '\0'
	res = (char *)malloc(ft_strlen(str) + 2); // +2 pq 'e o novo char que ta sendo alocado junto ao resto da string e o caracter nulo
	// Se não for possível alocar memória para a nova string, retornamos NULL
	if (!res)
		return (NULL);
	i = 0; // Inicializamos o índice como 0
	// Copiamos os caracteres da string de entrada para a nova string
	while (str[i])
	{
		res[i] = str[i]; // Copiamos o caractere atual
		i++; // Incrementamos o índice
	}
	res[i++] = c; // Adicionamos o caractere extra à nova string
	res[i] = 0; // Definimos o último caractere da nova string como '\0' (fim da string)
	free (str); // Liberamos a memória da string de entrada
	return (res); // Retornamos a nova string
}

