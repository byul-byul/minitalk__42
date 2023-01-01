#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	int		atoi;
	int		sign;

	atoi = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		atoi = atoi * 10 + (*nptr - '0');
		nptr++;
	}
	return (atoi * sign);
}

void	client(int server_pid)
{
	kill(server_pid, SIGUSR1);
	printf("\nclient: SIGUSR1 was send to pid = %d\n", server_pid);
	sleep(5);
	kill(server_pid, SIGUSR1);
	printf("\nclient: SIGUSR1 was send to pid = %d\n", server_pid);
	sleep(5);
	kill(server_pid, SIGUSR1);
	printf("\nclient: SIGUSR1 was send to pid = %d\n", server_pid);
	sleep(5);
	kill(server_pid, SIGUSR2);
	printf("\nclient: SIGUSR2 was send to pid = %d\n", server_pid);
	sleep(5);
	kill(server_pid, SIGUSR2);
	printf("\nclient: SIGUSR2 was send to pid = %d\n", server_pid);
	sleep(5);
	kill(server_pid, SIGUSR1);
	printf("\nclient: SIGUSR1 was send to pid = %d\n", server_pid);
	sleep(5);
	printf("\nclient: done\n");
}

int main(int ac, char **av)
{
	int		external_pid;

	external_pid = ft_atoi(av[1]);
	client(external_pid);
	return (0);
}
