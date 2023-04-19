#include "minitalk.h"

static void	welcome_msg()
{
	ft_putstr("Server's PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr("\nSIGUSR1 received\n");
	else if (signal == SIGUSR2)
		ft_putstr("\nSIGUSR2 received\n");
	else
		exit(0);
}

void	server(void)
{
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	welcome_msg();
	while (1)
		pause();
}
