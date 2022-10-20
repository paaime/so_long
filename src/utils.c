#include "../inc/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
	}
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}

int	ft_x_length(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	i -= 2;
	return (i);
}

int	ft_y_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	return (i);
}