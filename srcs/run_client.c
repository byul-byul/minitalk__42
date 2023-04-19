#include "minitalk.h"

int main(int ac, char **av)
{
	client(ac - 1, av + 1);
	return (0);
}
