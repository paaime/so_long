#include "../inc/so_long.h"

int	ft_move_left(t_game *game)
{
	if(game->map.map[game->player.y][game->player.x - 1] == '1')
		return (0);
	if(game->map.map[game->player.y][game->player.x] == 'E')
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/exit.xpm");
	else
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/bkg.xpm");
	game->player.x -= 1;
	if(game->map.map[game->player.y][game->player.x] == 'E')
	{
		if(game->map.collectibles == game->player.bitcoin)
		{
			ft_end_game(game);
			return (0);
		}
	}
	if(game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = '2';
		game->player.bitcoin += 1;
	}
	game->player.movement += 1;
	ft_print_image(&game->vars, game->player.x, game->player.y, "./img/player_left.xpm");
	return (0);
}

int	ft_move_right(t_game *game)
{
	if(game->map.map[game->player.y][game->player.x + 1] == '1')
		return (0);
	if(game->map.map[game->player.y][game->player.x] == 'E')
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/exit.xpm");
	else
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/bkg.xpm");
	game->player.x += 1;
	if(game->map.map[game->player.y][game->player.x] == 'E')
	{
		if(game->map.collectibles == game->player.bitcoin)
		{
			ft_end_game(game);
			return (0);
		}
	}
	if(game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = '2';
		game->player.bitcoin += 1;
	}
	game->player.movement += 1;
	ft_print_image(&game->vars, game->player.x, game->player.y, "./img/player_right.xpm");
	return (0);
}

int	ft_move_up(t_game *game)
{	/*if(game->map.map[game->player.y - 1][game->player.x] == '1')
		ft_rmplimage;*/
	if(game->map.map[game->player.y - 1][game->player.x] == '1')
		return (0);
	if(game->map.map[game->player.y][game->player.x] == 'E')
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/exit.xpm");
	else
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/bkg.xpm");
	game->player.y -= 1;
	if (game->map.map[game->player.y][game->player.x] == 'E')
	{
		if (game->map.collectibles == game->player.bitcoin)
		{
			ft_end_game(game);
			return (0);
		}
	}
	if(game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = '2';
		game->player.bitcoin += 1;
	}
	game->player.movement += 1;
	ft_print_image(&game->vars, game->player.x, game->player.y, "./img/player_up.xpm");
	return (0);
}

int	ft_move_down(t_game *game)
{
	if(game->map.map[game->player.y + 1][game->player.x] == '1')
		return (0);
	if(game->map.map[game->player.y][game->player.x] == 'E')
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/exit.xpm");
	else
		ft_print_image(&game->vars, game->player.x, game->player.y, "./img/bkg.xpm");
	/*ft_print_image(&game->vars, game->player.x, game->player.y, "./img/bkg.xpm");*/
	game->player.y += 1;
	if(game->map.map[game->player.y][game->player.x] == 'E')
	{
		if(game->map.collectibles == game->player.bitcoin)
		{
			ft_end_game(game);
			return (0);
		}
	}
	if(game->map.map[game->player.y][game->player.x] == 'C')
	{
		game->map.map[game->player.y][game->player.x] = '2';
		game->player.bitcoin += 1;
	}
	game->player.movement += 1;
	ft_print_image(&game->vars, game->player.x, game->player.y, "./img/player_down.xpm");
	return (0);
}
