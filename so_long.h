/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:31:37 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/21 12:35:23 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char	**map;
	int		column;
	int		line;
	int		move;
	int		x;
	int		y;
	int		e;
	int		p;
	int		c;
	void	*player;
	void	*door;
	void	*coin;
	void	*soil;
	void	*wall;
	void	*init;
	void	*win;
}			t_map;

int			close_window(t_map *maps);
void		ft_error(t_map maps, int error_code);
void		all_map_free(char **maps);
t_map		control(t_map maps);
t_map		fload_fill_and_exit(t_map maps);
t_map		open_window(t_map maps);
int			key_code(int keycode, t_map *maps);

#endif