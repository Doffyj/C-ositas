#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int x, int y)
{
	int	cont;
	int	cont2;

	cont = 1;
	while (cont <= y)
	{
		cont2 = 2;
		if (cont == 1 || cont == y)
		{
			ft_putchar(111);
			while (cont2 < y)
			{
				ft_putchar(45);
				cont2++;
			}
			ft_putchar(111);
		}
		else if (cont > 1 && cont < y)
		{
			ft_putchar(124);
			while (cont2 < y)
			{
				ft_putchar(32);
				cont2++;
			}
			ft_putchar(124);
		}
		ft_putchar(10);
		cont++;
	}
}

int	main(void)
{
	rush(500, 500);
	return (0);
}
