#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		printf("\nSIGUSR1 received\n");
	else if (signal == SIGUSR2)
		printf("\nSIGUSR2 received\n");
	else
		exit(0);
}

static void	server(void)
{
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	printf("Server's PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	while (1)
		pause();
}

int	main(void)
{
	server();
	return (0);
}
