#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		printf("\nSIGUSR1 received\n");
	else
		printf("\nunknown signal\n");
}

void	server(void)
{
	printf("Server's PID: %d\n", getpid());

	struct sigaction	sa;
	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		;
	}
}

int		main()
{
	server();
	return (0);
}
