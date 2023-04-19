#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define BITS_COUNT	8

typedef struct s_args
{
	int		server_pid;
	char	*msg;
}				t_args;

void	server(void);
void	client(int ac, char **av);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int 	ft_isonlydigits(char *s);
int		ft_atoi(const char *nptr);
void	print_err_and_exit(int errno);

#endif