/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:37:30 by paime             #+#    #+#             */
/*   Updated: 2022/10/20 22:10:39 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_init(t_game *game, char **map)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.movement = 0;
	game->player.bitcoin = 0;
	game->map.map = map;
	game->map.x_length = ft_x_length(map);
	game->map.y_length = ft_y_length(map);
	game->map.exit = 0;
	game->map.collectibles = 0;
	game->map.player = 0;
	return (0);
}

int	ft_check(t_game *game, char **map)
{
	if (!check_x_wall(game->map.map, game->map.y_length))
	{
		printf("Error \nWall ( up / down )");
		return (1);
	}	
	if (!check_y_wall(game->map.map, game->map.x_length))
	{
		printf("Error \nWall ( left / right )");
		return (1);
	}
	if (!check_rectangular(game, map))
	{
		printf("Error \nMap not rectangular.");
		return (1);
	}
	if (!check_ecp(game, map))
	{
		printf("Error \nCollectibles / exit / player");
		return (1);
	}
	return (0);
}

void	ft_end_game(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	exit(0);
}

void	ft_print_image(t_vars *vars, int x, int y, char *path)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * 64, y * 64);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 0)
		ft_move_left(game);
	else if (keycode == 2)
		ft_move_right(game);
	else if (keycode == 13)
		ft_move_up(game);
	else if (keycode == 1)
		ft_move_down(game);
	write(1, "Nombre de pas:", 15);
	ft_putnbr(game->player.movement);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	char	**map;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Map non reconnu.. \n");
			return (0);
		}
		map = find_map(fd);
		ft_init(&game, map);
		if (ft_check(&game, map))
			return (0);
		game.vars.mlx = mlx_init();
		game.vars.win = mlx_new_window(game.vars.mlx, game.map.x_length * 64 + 64, game.map.y_length * 64 + 64, "Hello !");
		ft_print_map(map, &game.vars);
		mlx_key_hook(game.vars.win, key_hook, &game);
		mlx_loop(game.vars.mlx);
	}

	printf("Indiquez une map.\n");
	return (0);
}
