/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:52:24 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/19 19:13:27 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_map	player_info(t_map maps)
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
	return (maps);
}

void	fload_fill(int y, int x, char **map)
{	
	if (map[y][x] == '1')
		return ;

	map[y][x] = '1';

	fload_fill(y + 1, x, map);
	fload_fill(y - 1, x, map);
	fload_fill(y, x + 1, map);
	fload_fill(y, x - 1, map);
}

int cpymap_control(char **cpymap)
{
	int column;
	int line;

	column=0;

	while (cpymap[column])
	{
		line =0;
		while (cpymap[column][line])
		{
			if (cpymap[column][line]=='1')
				line++;
			else
				return (5);
		}
		column++;
	}
	return (0);
}