#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_isonlydigits(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	long int	num;

	num = nb;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + 48);
	}
	else
		ft_putchar(num % 10 + 48);
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

void print_err_and_exit(int errno)
{
	if (errno == 1)
		ft_putstr("Validation error\n");
	else if (errno == 2)
		ft_putstr("malloc() error\n");
	else
		ft_putstr("Unknown error\n");
	exit(0);
}

void	dec_to_binary(int num, int byte[BITS_COUNT])
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

int	binary_to_dec(int byte[BITS_COUNT])
{
	int	i;
	int	base;
	int	dec;

	dec = 0;
	base = 1;
	i = BITS_COUNT;
	while (--i > -1)
	{
		// printf("i = %d, byte[%d] = %d, decP = %d\n", i, i, byte[i], dec);
		dec += byte[i] * base;
		base *= 2;
		// printf("decA = %d\n\n", dec);
	}
	return (dec);
}
