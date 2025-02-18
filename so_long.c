#include "get_next_line.h"
#include "so_long.h"
#include <stdio.h>//sill
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

static char **all_read_map(char** map,char **av)
{
    char *str;
    char *newstr;
    int fd;
    char *tmp;
    newstr=ft_strdup("");
    fd=open(av[1],O_RDONLY);

    while (1)
    {
        str=get_next_line(fd);
        if (!str)
        break;
        tmp=newstr;
        newstr=ft_strjoin(newstr,str);
        free(tmp);
        free(str);
    }
    tmp=newstr;
    newstr=ft_strjoin(newstr,"1");
    free(tmp);
    map=ft_split(newstr,'\n');
    free(newstr);
    return map;
}

void all_map_free(t_map maps)
{
    int i;
    i=-1;
    while (maps.map[++i])
        free(maps.map[i]);
    free(maps.map); 
}
void ft_error(t_map maps)
{
    all_map_free(maps);
    write(1,"Error\n",6);
    exit(1);
}

void all_map_print(char**map)
{
    int i;
    i=-1;
    while (map[++i])
        printf("%s\n",map[i]);
}

int main(int ac,char **av)
{
    t_map maps;

    maps.map=all_read_map(maps.map,av);
    control(maps);
    all_map_print(maps.map);
    all_map_free(maps);
    return 0;
}