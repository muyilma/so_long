/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fload_fill_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:52:24 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/21 15:42:56 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

static t_map	player_info(t_map maps)
{
	int	column;
	int	line;

	column = 0;
	while (maps.map[column])
	{
		line = 0;
		while (maps.map[column][line])
		{
			if (maps.map[column][line] == 'P')
			{
				maps.y = column;
				maps.x = line;
			}
			line++;
		}
		column++;
	}
	maps.move = 1;
	return (maps);
}

static void	fload_fill(int y, int x, char **map)
{
	char	c;

	c = map[y][x];
	if (c== '1')
		return ;
	map[y][x] = '1';
	if (c== 'E')
		return ;
	fload_fill(y + 1, x, map);
	fload_fill(y - 1, x, map);
	fload_fill(y, x + 1, map);
	fload_fill(y, x - 1, map);
}

static int	cpymap_control(char **cpymap)
{
	int	column;
	int	line;

	column = 0;
	while (cpymap[column])
	{
		line = 0;
		while (cpymap[column][line])
		{
			if (cpymap[column][line] == '1')
				line++;
			else
				return (5);
		}
		column++;
	}
	return (0);
}

static char	**map_copy(t_map maps)
{
	int		column;
	char	**cpymap;
	int		i;

	column = maps.column;
	cpymap = malloc(sizeof(char *) * (column + 1));
	column = 0;
	while (maps.map[column])
	{
		cpymap[column] = malloc(maps.line + 1);
		i = 0;
		while (maps.map[column][i])
		{
			cpymap[column][i] = maps.map[column][i];
			i++;
		}
		cpymap[column][i] = '\0';
		column++;
	}
	cpymap[column] = NULL;
	return (cpymap);
}
#include <stdio.h>

void	all_map_print(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

t_map	fload_fill_and_exit(t_map maps)
{
	char	**cpymap;

	cpymap = map_copy(maps);
	maps = player_info(maps);
	fload_fill(maps.y, maps.x, cpymap);
	all_map_print(cpymap);
	if (cpymap_control(cpymap) == 5)
	{
		all_map_free(cpymap);
		ft_error(maps, 5);
	}
	all_map_free(cpymap);
	return (maps);
}
