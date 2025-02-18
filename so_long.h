#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_map
{
    char **map;
} t_map;

void control(t_map maps);
void all_map_free(t_map maps);
void ft_error(t_map maps);

#endif 