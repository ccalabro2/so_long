#ifndef SO_LONG_H
# define SO_LONG_H
# include "./utils/utils.h"
# include <fcntl.h>

typedef struct s_map {
    char	**maps;
    int		width;
    int		height;
}	t_map;

typedef struct s_info {
    int	c_coin;
    int	c_player;
    int	c_exit;
    void	*wall;
    void	*floor;
    void	*player;
    void	*coin;
    void	*exit;
}	t_info;

typedef struct s_game {
    t_map	*map;
    char	**mapcopy;
    t_info	*info;
    void	*mlx_ptr;
    void	*mlx_win;
    char	*file_path;
    int		x;
    int		y;
} t_game;

int		init_info(t_game *game);
int 	init_map(t_game *game);
int		check_path(t_game *game);
void	check_map(t_game *game);
void	ft_exit(t_game *game, int flag);
int		key_hook(int keycode, t_game *game);
int		exit_hook(t_game *game);
void	render_map(t_game *game);
void	render_tile(t_game *game, int x, int y, char tile);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
