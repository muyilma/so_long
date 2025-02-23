/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:22:58 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/22 11:34:12 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

static t_map	all_read_map(t_map maps, char **av)
{
	char	*str;
	char	*newstr;
	int		fd;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	newstr = ft_strdup("");
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tmp = newstr;
		newstr = ft_strjoin(newstr, str);
		free(tmp);
		free(str);
	}
	tmp = newstr;
	newstr = ft_strjoin(newstr, "1");
	free(tmp);
	maps.map = ft_split(newstr, '\n');
	free(newstr);
	return (maps);
}

void	all_map_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_error(t_map maps, int error_code)
{
	all_map_free(maps.map);
	write(1, "Error\n", 6);
	if (error_code == 0)
		write(1, "Map not rectangle!!\n", 21);
	else if (error_code == 1)
		write(1, "Not enough line for Map!!\n", 27);
	else if (error_code == 2)
		write(1, "Map not surrounded wall!!\n", 27);
	else if (error_code == 3)
		write(1, "Unknown argument!!\n", 20);
	else if (error_code == 4)
		write(1, "Wrong argument count!!\n", 24);
	else if (error_code == 5)
		write(1, "Map is not reachable!!\n", 24);
	exit(1);
}

int	close_window(t_map *maps)
{
	mlx_destroy_image(maps->init, maps->player);
	mlx_destroy_image(maps->init, maps->coin);
	mlx_destroy_image(maps->init, maps->soil);
	mlx_destroy_image(maps->init, maps->door);
	mlx_destroy_image(maps->init, maps->wall);
	mlx_destroy_window(maps->init, maps->win);
	mlx_destroy_display(maps->init);
	free(maps->init);
	all_map_free(maps->map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	maps;

	if (ac == 2)
	{
		maps = all_read_map(maps, av);
		if (!maps.map)
			ft_error(maps, -1);
		maps = control(maps);
		maps = fload_fill_and_exit(maps);
		maps = open_window(maps);
		mlx_hook(maps.win, 2, (1L << 0), key_code, &maps);
		mlx_hook(maps.win, 17, 0, close_window, &maps);
		mlx_loop(maps.init);
	}
}
