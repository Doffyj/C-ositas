#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_midln(int y)
{
	int	cont;

	cont = 2;
	ft_putchar(124);
	while (cont < y)
	{
		ft_putchar(32);
		cont++;
	}
	ft_putchar(124);
	ft_putchar(10);
}

void	ft_lastln(int y)
{
	int	cont;

	cont = 2;
	ft_putchar(111);
	while (cont < y)
	{
		ft_putchar(45);
		cont++;
	}
	ft_putchar(111);
	ft_putchar(10);
}

void	rush(int x, int y)
{
	int	xclon;

	xclon = 2;
	ft_lastln(y);
	while (xclon < y)
	{
		ft_midln(y);
		xclon++;
	}
	ft_lastln(y);
}

int	main(void)
{
	rush(50, 50);
	return (0);
}
