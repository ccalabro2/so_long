#include "so_long.h"
#include "mlx/mlx.h"

// PROBLEMINI:
// 1) gestire la \n alla fine della mappa
// 2) il make clean in mlx ha qualcosa che non va
// 3) se avvii il gioco, non tocchi nulla ed esci subito va in segfault
// 4) in generale sto so_long è come una melanzana nel culo

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || ft_endcmp(argv[1], ".ber"))
		return (ft_printf("Invalid arguments! :c\n"), 1);
	
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->file_path = argv[1];
	check_map(game);  
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map->width * 80, game->map->height * 80, "REPARTO ORTOFRUTTICULO");
	if (!game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	set_images(game);
	render_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0, exit_hook, game);
	mlx_loop(game->mlx_ptr);
	
	ft_exit(game);

	return (0);
}

