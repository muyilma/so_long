#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h> //sill
#include <unistd.h>
#include "minilibx/mlx.h"

static char **all_read_map(char **map, char **av)
{
	char *str;
	char *newstr;
	int fd;
	char *tmp;

	newstr = ft_strdup("");
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		tmp = newstr;
		newstr = ft_strjoin(newstr, str);
		free(tmp);
		free(str);
	}
	tmp = newstr;
	newstr = ft_strjoin(newstr, "1");
	free(tmp);
	map = ft_split(newstr, '\n');
	free(newstr);
	return (map);
}

void all_map_free(char **map)
{
	int i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
void ft_error(t_map maps, int error_code)
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

void all_map_print(char **map)
{
	int i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

char **map_copy(t_map maps)
{
	int column;
	char **cpymap;
	int i;

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

int close_window(t_map *maps)
{
	all_map_free(maps->map);
    exit(0);   
}


int main(int ac, char **av)
{
	t_map maps;
	char **cpymap;

	maps.map = all_read_map(maps.map, av);
	maps=control(maps);
	cpymap = map_copy(maps);
	maps = player_info(maps);
	fload_fill(maps.y, maps.x, cpymap);
	if (cpymap_control(cpymap) == 5)
	{
		all_map_free(cpymap);
		ft_error(maps, 5);
	}
	maps=open_window(maps);
	mlx_hook(maps.win,2,(1L << 0),key_code,&maps);
	mlx_hook(maps.win,17,0,close_window,&maps);
	mlx_loop(maps.init);
	all_map_print(maps.map);
	all_map_free(maps.map);
	all_map_free(cpymap);
}
