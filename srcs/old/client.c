#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int ft_isonlydigits(char *s)
{
	while (*s != '\0')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_ptr;
	char		*dest_ptr;

	if (dest == src)
		return (dest);
	src_ptr = src;
	dest_ptr = dest;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result)
	{
		ft_memcpy(result, s1, s1_len);
		ft_memcpy(result + s1_len, s2, s2_len + 1);
	}
	return (result);
}

static void print_err_and_exit(int errNo)
{
	if (errNo == 1)
		printf("\nERR_No_1\n");
	else if (errNo == 2)
		printf("\nERR_No_2\n");
	else
		printf("\nERR_No_?\n");
	exit(0);
}

static void send_message(t_args args)
{
	int	count = 3;
	while (count--)
	{
		printf("\niter_No: %d\n", count);
		kill(args.server_pid, SIGUSR1);
		printf("client: SIGUSR1 was send to pid = %d\nwith msg = %s\n", args.server_pid,args.msg);
		sleep(5);
		kill(args.server_pid, SIGUSR2);
		printf("client: SIGUSR2 was send to pid = %d\nwith msg = %s\n", args.server_pid,args.msg);
		sleep(5);
	}
	kill(args.server_pid, SIGTERM);
	printf("\nclient: done\n");
}

static void	validate_and_parse_args(int ac, char **av, t_args *args)
{
	if (ac < 2)
		print_err_and_exit(1);
	if (!ft_isonlydigits(av[1]))
		print_err_and_exit(2);

	int		i = 2;
	char	*tmp = NULL;
	char	*msg = malloc(1);
	while (i < ac)
	{
		tmp = msg;
		msg = ft_strjoin(msg, av[i]);
		free(tmp);
		i++;
	}
	args->server_pid = ft_atoi(av[1]);
	args->msg = msg;
}


static void	client(int ac, char **av)
{
	t_args	args;

	validate_and_parse_args(ac, av, &args);
	send_message(args);
}

int main(int argc, char **argv)
{
	client(argc, argv);
	return (0);
}
