/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:49:41 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 17:37:54 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./utils/utils.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**maps;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	char	**mapcopy;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*file_path;
	int		x;
	int		y;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
	int		c_coin;
	int		c_player;
	int		c_exit;
	int		steps;
}	t_game;

int		init_game(t_game *game);
int		init_map(t_game *game);
int		check_path(t_game *game);
void	check_map(t_game *game);
void	ft_exit(t_game *game);
int		key_hook(int keycode, t_game *game);
int		exit_hook(t_game *game);
void	set_images(t_game *game);
void	render_map(t_game *game);
void	render_tile(t_game *game, int x, int y, char tile);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
