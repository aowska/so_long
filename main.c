/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:09:43 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/02 21:09:44 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_so_long.h"

void ft_free_game(t_game *game)
{
    // Zwolnij pamięć dla tablicy map
    if (game->map != NULL) 
	{
        int i = 0;
        while (game->map[i] != NULL) 
		{
            free(game->map[i]);
            i++;
        }
        free(game->map);
	}

    // Zwolnij pamięć dla obrazków
    // (Jeśli są to obrazy wczytane za pomocą mlx_xpm_file_to_image,
    // należy użyć odpowiedniej funkcji do zwolnienia pamięci dla każdego obrazka)
    if (game->img != NULL) {
        mlx_destroy_image(game->mlx, game->img);
    }
    if (game->img2 != NULL) {
        mlx_destroy_image(game->mlx, game->img2);
    }
    if (game->img3 != NULL) {
        mlx_destroy_image(game->mlx, game->img3);
    }
    if (game->img4 != NULL) {
        mlx_destroy_image(game->mlx, game->img4);
    }
    if (game->img5 != NULL) {
        mlx_destroy_image(game->mlx, game->img5);
    }
    // Zwolnij pamięć dla samej struktury t_game
    free(game);
}


int on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_game(data);
	free(data->mlx);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_game *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int ft_game_initialization(t_game *game) 
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error: Failed to initialize mlx\n"), 1);

	game->win = NULL;
	game->w	= 0;
	game->h = 0;		
	game->img = NULL;
	game->img2 = NULL;
	game->img3 = NULL;
	game->img4 = NULL;
	game->img5 = NULL;
	game->map = NULL;

	return (0);
}


void ft_mlx_xpm_file_to_image(t_game *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./textures/1.xpm", &data->w, &data->h);
	data->img2 = mlx_xpm_file_to_image(data->mlx, "./textures/0.xpm", &data->w, &data->h);
	data->img3 = mlx_xpm_file_to_image(data->mlx, "./textures/P.xpm", &data->w, &data->h);
	data->img4 = mlx_xpm_file_to_image(data->mlx, "./textures/C.xpm", &data->w, &data->h);
	data->img5 = mlx_xpm_file_to_image(data->mlx, "./textures/E.xpm", &data->w, &data->h);
}

void ft_mlx_put_image_to_window(t_game *data, size_t h, size_t w)
{
	ft_printf("%d\n", (int)data->h);
	ft_printf("%d\n", (int)data->w);
    size_t i = 0, j;
    while (i < h)
	{
        j = 0;
        while (j < w) 
		{
            int x = j * 32;
            int y = i * 32;
            if (data->map[i][j].value == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
			if (data->map[i][j].value == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->img2, x, y);
            if (data->map[i][j].value == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->img3, x, y);
            if (data->map[i][j].value == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->img4, x, y);
            if (data->map[i][j].value == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->img5, x, y);
            j++;
        }
        i++;
    }
}


int main (int ac, char **av)
{
	t_game data;
	size_t h;
	size_t w;
	
	h = 0;
	w = 0;
	if (ac != 2)
		return(ft_printf(ERR_ARG), 0);
	ft_game_initialization(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error: mlx is not initialized\n"), 1);
	if(ft_map(av[1], &data) != 0)
		return (ft_free_game(&data), 1);
	h = (size_t)data.h;
	w = (size_t)data.w;
    data.win = mlx_new_window(data.mlx, data.w * 32, data.h * 32, "so_long");
	if (!data.win)
		return (free(data.mlx), ft_free_game(&data), 1);
	ft_mlx_xpm_file_to_image(&data);
	ft_mlx_put_image_to_window(&data, h, w);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
	
	ft_free_game(&data);
	return (0);
}
