/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:56:41 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/21 11:28:04 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

static t_map	map_info(t_map maps)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	while (maps.map[0][line])
		line++;
	while (maps.map[column])
		column++;
	maps.line = line;
	maps.column = column;
	return (maps);
}

static void	rectangle(t_map maps)
{
	int	i;
	int	j;

	i = 0;
	while (maps.map[i])
	{
		j = 0;
		while (maps.map[i][j])
			j++;
		if (j != maps.line)
			ft_error(maps, 0);
		i++;
	}
}

static void	all_wall(t_map maps)
{
	int	i;
	int	j;

	if (maps.column < 3)
		ft_error(maps, 1);
	i = 0;
	while (maps.map[i])
	{
		j = 0;
		while (maps.map[i][j])
		{
			if (i == 0 || i == maps.column || j == 0 || j == maps.line - 1)
			{
				if (maps.map[i][j] != '1')
					ft_error(maps, 2);
			}
			j++;
		}
		i++;
	}
}

static t_map	map_contain(t_map maps, int i, int j, int nothing)
{
	maps.c = 0;
	maps.e = 0;
	maps.p = 0;
	while (maps.map[i])
	{
		j = 0;
		while (maps.map[i][j])
		{
			if (maps.map[i][j] == '0' || maps.map[i][j] == '1')
				nothing++;
			else if (maps.map[i][j] == 'P')
				maps.p++;
			else if (maps.map[i][j] == 'E')
				maps.e++;
			else if (maps.map[i][j] == 'C')
				maps.c++;
			else
				ft_error(maps, 3);
			j++;
		}
		i++;
	}
	if (!(maps.p == 1 && maps.c >= 1 && maps.e == 1))
		ft_error(maps, 4);
	return (maps);
}

t_map	control(t_map maps)
{
	maps = map_info(maps);
	rectangle(maps);
	all_wall(maps);
	maps = map_contain(maps, 0, 0, 0);
	return (maps);
}
