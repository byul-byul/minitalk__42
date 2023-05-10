#include "minitalk.h"
#include "server.h"

static void	welcome_msg()
{
	ft_putstr("Server's PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

static void	signal_handler(int signal)
{
	int	dec;
	int	byte[BITS_COUNT];

	bit_i++;
	if (signal == SIGUSR1)
		byte[bit_i] = 1;
	else if (signal == SIGUSR2)
		byte[bit_i] = 0;
	// printf("byte[%d] = %d\n", bit_i, byte[bit_i]);
	if (bit_i == BITS_COUNT - 1)
	{
		bit_i = -1;
		dec = binary_to_dec(byte);
		ft_putchar(dec);
		// printf("binary_to_dec(): dec = %d\n", dec);
		// printf("char = %c\n", dec);
	}
}

void	server(void)
{
	struct sigaction	sa;

	bit_i = -1;
	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	welcome_msg();
	while (1)
		pause();
}
