/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:56:41 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/19 15:59:39 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	map_info(t_map maps, int info)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	if (info == 1)
	{
		while (maps.map[0][line])
			line++;
		return (line);
	}
	else if (info == 2)
	{
		while (maps.map[column])
			column++;
		return (column);
	}
	return (0);
}

void	rectangle(t_map maps, int line)
{
	int	i;
	int	j;

	i = 0;
	while (maps.map[i])
	{
		j = 0;
		while (maps.map[i][j])
			j++;
		if (j != line)
			ft_error(maps, 0);
		i++;
	}
}

void	all_wall(t_map maps, int line)
{
	int	column;
	int	i;
	int	j;

	column = map_info(maps, 2);
	if (column < 3)
		ft_error(maps, 1);
	i = 0;
	while (maps.map[i])
	{
		j = 0;
		while (maps.map[i][j])
		{
			if (i == 0 || i == column || j == 0 || j == line)
			{
				if (maps.map[i][j] != '1')
					ft_error(maps, 2);
			}
			j++;
		}
		i++;
	}
}
void	map_contain(t_map maps, int i, int j, int nothing)
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
}

void	control(t_map maps)
{
	int	len;

	len = map_info(maps, 1);
	rectangle(maps, len);
	all_wall(maps, len - 1);
	map_contain(maps, 0, 0, 0);
}
