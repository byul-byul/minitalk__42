#include "minitalk.h"

static void send_byte(int pid, int byte[BITS_COUNT])
{
	int i = -1;
	while (++i < BITS_COUNT)
	{
		// printf("%d", byte[i]);
		if (byte[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	// printf("\n");
}

static void	send_char(int pid, char letter)
{
	int		ascii_code;
	int		byte[BITS_COUNT];

	ascii_code = letter;
	dec_to_binary(ascii_code, byte);
	send_byte(pid, byte);
}

static void	send_message(int pid, char *msg)
{
	while (*msg)
		send_char(pid, *msg++);
}

static void	parse_args(char **av, t_args *args)
{
	args->server_pid = ft_atoi(av[0]);
	args->msg = av[1];
}

static int	is_valid_args(int ac, char **av)
{
	if (ac != 2)
		print_err_and_exit(1);
	if (!ft_isonlydigits(av[0]))
		print_err_and_exit(1);
	return (1);
}

void	client(int ac, char **av)
{
	t_args	args;

	if (is_valid_args(ac, av))
	{
		parse_args(av, &args);
		send_message(args.server_pid, args.msg);
	}
}
