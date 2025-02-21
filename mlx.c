/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:24:22 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/21 14:01:53 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	a;
	int	b;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
	{
		write(1, "2", 1);
		nb = 147483648;
	}
	b = nb / 10;
	if (nb > 9)
		ft_putnbr(b);
	a = (nb % 10) + 48;
	write(1, &a, 1);
}

static t_map	mlx_color(t_map m)
{
	int	i;
	int	j;

	i = 0;
	while (m.map[i])
	{
		j = 0;
		while (m.map[i][j])
		{
			if (m.map[i][j] == '1')
				mlx_put_image_to_window(m.init, m.win, m.wall, j * 64, i * 64);
			else if (m.map[i][j] == '0')
				mlx_put_image_to_window(m.init, m.win, m.soil, j * 64, i * 64);
			else if (m.map[i][j] == 'C')
				mlx_put_image_to_window(m.init, m.win, m.coin, j * 64, i * 64);
			else if (m.map[i][j] == 'E')
				mlx_put_image_to_window(m.init, m.win, m.door, j * 64, i * 64);
			else if (m.map[i][j] == 'P')
				mlx_put_image_to_window(m.init, m.win, m.player, j * 64, i
					* 64);
			j++;
		}
		i++;
	}
	return (m);
}

t_map	open_window(t_map maps)
{
	int	i;

	i = 64;
	maps.init = mlx_init();
	maps.win = mlx_new_window(maps.init, maps.line * i, maps.column * i,
			"Find The Treasure!!");
	maps.coin = mlx_xpm_file_to_image(maps.init, "textures/coin.xpm", &i, &i);
	maps.player = mlx_xpm_file_to_image(maps.init, "textures/player.xpm", &i,
			&i);
	maps.wall = mlx_xpm_file_to_image(maps.init, "textures/wall.xpm", &i, &i);
	maps.soil = mlx_xpm_file_to_image(maps.init, "textures/soil.xpm", &i, &i);
	maps.door = mlx_xpm_file_to_image(maps.init, "textures/door.xpm", &i, &i);
	maps = mlx_color(maps);
	return (maps);
}

static void	player_move(t_map *maps, int dx, int dy)
{
	if (maps->map[maps->y + dy][maps->x + dx] != '1')
	{
		if (maps->map[maps->y + dy][maps->x + dx] == 'C')
			maps->c--;
		if (maps->map[maps->y + dy][maps->x + dx] == 'E' && maps->c == 0)
		{
			close_window(maps);
			return ;
		}
		if (maps->map[maps->y + dy][maps->x + dx] == 'E')
			return ;
		ft_putnbr(maps->move);
		maps->move++;
		write(1, "\n", 1);
		maps->map[maps->y][maps->x] = '0';
		maps->map[maps->y + dy][maps->x + dx] = 'P';
		maps->y += dy;
		maps->x += dx;
	}
	mlx_color(*maps);
}

int	key_code(int keycode, t_map *maps)
{
	if (keycode == 65307)
		close_window(maps);
	else if (keycode == 119 || keycode == 65362)
		player_move(maps, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		player_move(maps, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		player_move(maps, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		player_move(maps, 1, 0);
	return (0);
}
