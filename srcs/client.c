#include "minitalk.h"
#include <stdio.h>

static void send_byte(int pid, int byte[BITS_COUNT])
{
	(void)pid;
	int i = -1;
	while (++i < BITS_COUNT)
		printf("%d", byte[i]);
	ft_putchar('\n');
}

static void	dec_to_binary(int num, int byte[BITS_COUNT])
{
	int	i;

	i = -1;
	while (++i < BITS_COUNT)
		(byte)[i] = 0;
	while (--i > -1)
	{
		(byte)[i] = num % 2;
		num /= 2;
	}
}

static void	send_char(int pid, char letter)
{
	int		ascii_code;
	int		byte[BITS_COUNT];

	ascii_code = letter;
	dec_to_binary(ascii_code, byte);
	send_byte(pid, byte);
}

// static void	send_char(int pid, char letter)
// {
// 	int		ascii_code;
// 	int		reminder;

// 	printf("\nletter = %c, ascii_code = %d\n", letter, ascii_code);
// 	while (ascii_code != 0)
// 	{
// 		reminder = ascii_code % 2;
// 		printf("%d", reminder);
// 		if (reminder == 1)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		ascii_code /= 2;
// 	}
// }

static void	send_message(int pid, char *msg)
{
	while (*msg)
		send_char(pid, *msg++);
	
	// int	count = 3;
	// while (count--)
	// {
	// 	printf("\niter_No: %d\n", count);
	// 	kill(args.server_pid, SIGUSR1);
	// 	printf("client: SIGUSR1 was send to pid = %d\nwith msg = %s\n", args.server_pid, args.msg);
	// 	sleep(5);
	// 	kill(args.server_pid, SIGUSR2);
	// 	printf("client: SIGUSR2 was send to pid = %d\nwith msg = %s\n", args.server_pid, args.msg);
	// 	sleep(5);
	// }
	// kill(args.server_pid, SIGTERM);
	// printf("\nclient: done\n");
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
