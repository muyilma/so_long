#include "so_long.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int column_len(char **column)
{
    int i;
    i=0;
    while (column[i])
        i++;
    return (i);
}
void rectangle(t_map maps,int line)
{
    int i;
    int j;
    i=0;
    while (maps.map[i])
    {
        j=0;
        while (maps.map[i][j])
            j++;
        if (j!=line)
            ft_error(maps);
        i++;
    }
}
int line_len(char *line)
{
    int i;
    i=0;
    while (line[i])
        i++;
    return (i);
}

void all_wall(t_map maps,int line)
{
    int column;
    int i;
    int j;
    column=column_len(maps.map)-1;
    if (column<=1)
    ft_error(maps);
    
    i=0;
    while (maps.map[i])
    {
        j=0;
        while (maps.map[i][j])
        {
            if (i==0 || i==column || j==0 || j==line)
            {
                if (maps.map[i][j]!='1')
                    ft_error(maps); 
            }
            j++;
        }
        i++;
    }
}
void map_contain(t_map maps, int p, int c, int e)
{
    int i;
    int j;
    i=0;

    while (maps.map[i])
    {
        j=0;
        while (maps.map[i][j])
        {
            if (maps.map[i][j]=='0' || maps.map[i][j]=='1')
            {
                j++;
                continue;
            }
            else if (maps.map[i][j]=='P')
                p++;
            else if (maps.map[i][j]=='E')
                e++;
            else if (maps.map[i][j]=='C')
                c++;
            else
                ft_error(maps);
            j++;
        }
        i++;
    }
    if (!(p==1 && c>=1 && e==1))
        ft_error(maps);
}


void control(t_map maps)
{
    int len;   
    len=line_len(maps.map[0]);
    rectangle(maps,len);
    all_wall(maps,len-1);
    map_contain(maps,0,0,0);
    
    //pce01
}


 