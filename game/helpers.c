#include "../so_long.h"

void    ft_free_matrix(t_game *game)
{
    int i;

    i = -1;
    if (game->map && game->map->maps)
    {
        while (++i < game->map->height)
            free(game->map->maps[i]);
        free(game->map->maps);
    }
    i = -1;
    if (game->mapcopy)
    {
        while (++i < game->map->height)
        {
            if (game->mapcopy[i])
                free(game->mapcopy[i]);
        }
        free(game->mapcopy);
    }
}

void    ft_exit(t_game *game, int flag)
{
    if (flag > 0)
        ft_free_matrix(game);
    if (flag > 1)
        free(game->info);
    if (game->map)
        free(game->map);
    free(game);
}