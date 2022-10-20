/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paime <paime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:45 by paime             #+#    #+#             */
/*   Updated: 2021/12/14 17:55:47 by paime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_y_wall(char **map, int x_length)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][x_length] != '1' && map[i][x_length] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_x_wall(char **map, int y_length)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (map[y_length][i])
	{
		if (map[y_length][i] != '1' && map[y_length][i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectangular(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			j++;
		}
		if (j != game->map.x_length + 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_init_player(t_game *game, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	game->map.player += 1;
}

int	check_ecp(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				game->map.exit += 1;
			else if (map[i][j] == 'C')
				game->map.collectibles += 1;
			else if (map[i][j] == 'P')
				ft_init_player(game, i, j);
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (!game->map.exit || !game->map.collectibles || game->map.player != 1)
		return (0);
	return (1);
}

char	**find_map(int fd)
{
	char	*line;
	char	**map;
	int		i;
	int		size;

	i = 0;
	size = 0;
	map = malloc(sizeof(char) * 1000);
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		map[i] = line;
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int	ft_print_map(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				ft_print_image(vars, j, i, "./img/barrel.xpm");
			else if (map[i][j] == '0')
				ft_print_image(vars, j, i, "./img/bkg.xpm");
			else if (map[i][j] == 'C')
				ft_print_image(vars, j, i, "./img/coin.xpm");
			else if (map[i][j] == 'E')
				ft_print_image(vars, j, i, "./img/exit.xpm");
			else if (map[i][j] == 'P')
				ft_print_image(vars, j, i, "./img/player.xpm");
			j++;
		}
		i++;
	}
	return (0);
}
