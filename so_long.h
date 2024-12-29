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
}	t_info;

typedef struct s_game {

	t_map	*map;
	t_info	*info;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*file_path;

} t_game;

#endif
