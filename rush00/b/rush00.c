void	ft_putchar(char c);

void	ft_midln(int x)
{
	int	cont;

	cont = 2;
	ft_putchar(124);
	if (x >= 2)
	{
		while (cont < x)
		{
			ft_putchar(32);
			cont++;
		}
		ft_putchar(124);
	}
	ft_putchar(10);
}

void	ft_lastln(int x)
{
	int	cont;

	cont = 2;
	ft_putchar(111);
	if (x >= 2)
	{
		while (cont < x)
		{
			ft_putchar(45);
			cont++;
		}
		ft_putchar(111);
	}
	ft_putchar(10);
}

void	rush(int x, int y)
{
	int	i;

	i = 2;
	if (x == 0 || y == 0)
	{
		ft_putchar(10);
	}
	else 
	{
		ft_lastln(x);
		while (i < y)
		{
			ft_midln(x);
			i++;
		}
		if (y > 1)
		{
			ft_lastln(x);
		}
	}
}
