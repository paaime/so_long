/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paime <paime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:58:16 by paime             #+#    #+#             */
/*   Updated: 2021/12/14 18:21:24 by paime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../inc/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_play {
    int x;
    int y;
    int bitcoin;
    int movement;
} t_play;

typedef struct s_map {
    char    **map;
    int     x_length;
    int     y_length;
    int     collectibles;
    int     exit;
    int     player;
} t_map;

typedef struct s_vars {
    void    *mlx;
    void    *win;
} t_vars;

typedef struct s_game {
    t_vars  vars;
    t_map   map;
    t_play  player;
}   t_game;

int     ft_move_left(t_game *game);
int     ft_move_right(t_game *game);
int     ft_move_up(t_game *game);
int     ft_move_down(t_game *game);
void    ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_print_tab(char **tab);
int     ft_x_length(char **map);
int     ft_y_length(char **map);
int     check_y_wall(char **map, int x_length);
int     check_x_wall(char **map, int y_length);
int     check_ecp(t_game *game, char **map);
char	**find_map(int fd);
int     ft_print_map(char **map, t_vars *vars);
int     check_rectangular(t_game *game, char **map);
void	ft_end_game(t_game *game);
void	ft_print_image(t_vars *vars, int x, int y, char *path);

#endif