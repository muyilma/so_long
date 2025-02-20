#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char **map;
	int column;
	int line;
	int x;
	int y;
	int e;
	int p;
	int c;
	void* player;
	void* door;
	void* coin;
	void* soil;
	void* wall;
	void* init;
	void* win;
} t_map;

t_map open_window(t_map maps);
t_map	control(t_map maps);
void	all_map_free(char **maps);
void	ft_error(t_map maps, int error_code);
t_map	map_info(t_map maps);
t_map	player_info(t_map maps);
void	fload_fill(int y, int x, char **map);
void	all_map_print(char **map);
int cpymap_control(char **cpymap);
t_map mlx_color(t_map m);
int key_code(int keycode, t_map *maps);
int close_window(t_map *maps);

#endif