#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char **map;
	int x;
	int y;
	int e;
	int p;
	int c;
} t_map;

void	control(t_map maps);
void	all_map_free(char **maps);
void	ft_error(t_map maps, int error_code);
int	map_info(t_map maps, int info);
t_map	player_info(t_map maps);
void	fload_fill(int y, int x, char **map);
void	all_map_print(char **map);

#endif