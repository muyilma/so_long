#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h> //sill
#include <unistd.h>

static char	**all_read_map(char **map, char **av)
{
	char	*str;
	char	*newstr;
	int		fd;
	char	*tmp;

	newstr = ft_strdup("");
	fd = open(av[1], O_RDONLY);
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
	map = ft_split(newstr, '\n');
	free(newstr);
	return (map);
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
		write(1, "Map not rectangle!!", 20);
	else if (error_code == 1)
		write(1, "Not enough line for Map!!", 26);
	else if (error_code == 2)
		write(1, "Map not surrounded wall!!", 26);
	else if (error_code == 3)
		write(1, "Unknown argument!!", 19);
	else if (error_code == 4)
		write(1, "Wrong argument count!!", 23);
	exit(1);
}

void	all_map_print(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

char	**map_copy(t_map maps)
{
	int		line;
	int		column;
	char	**cpymap;
	int		i;

	line = map_info(maps, 1);
	column = map_info(maps, 2);
	cpymap = malloc(sizeof(char *) * (column + 1));
	column = 0;
	while (maps.map[column])
	{
		cpymap[column] = malloc(line + 1);
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

int	main(int ac, char **av)
{
	t_map	maps;
	char	**cpymap;

	maps.map = all_read_map(maps.map, av);
	control(maps);
	cpymap = map_copy(maps);
	maps=player_info(maps);
	fload_fill(maps.y,maps.x,cpymap);
	all_map_print(cpymap);
	all_map_free(maps.map);
	all_map_free(cpymap);
	return (0);
}
