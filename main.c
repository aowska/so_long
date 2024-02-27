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

int	ft_game_initialization(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error: Failed to initialize mlx\n"), 1);
	game->win = NULL;
	game->w = 0;
	game->h = 0;
	game->img = NULL;
	game->img2 = NULL;
	game->img3 = NULL;
	game->img4 = NULL;
	game->img5 = NULL;
	game->map = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	return (0);
}

int	initialize_and_configure_game(int ac, char **av, t_game *data)
{
	size_t	h;
	size_t	w;

	h = 0;
	w = 0;
	if (ac != 2)
		return (ft_printf(ERR_ARG), 0);
	ft_game_initialization(data);
	if (ft_map(av[1], data) != 0)
		return (ft_free_game(data), 1);
	h = (size_t)data->h;
	w = (size_t)data->w;
	data->win = mlx_new_window(data->mlx, 
			data->w * 64, data->h * 64, "so_long");
	if (!data->win)
		return (ft_free_game(data), 1);
	ft_mlx_xpm_file_to_image(data);
	data->h = (size_t)h;
	data->w = (size_t)w;
	return (0);
}

void	event_loop_and_cleanup(t_game *data)
{
	mlx_key_hook(data->win, &ft_key_hook, data);
	mlx_hook(data->win, DestroyNotify, 
		StructureNotifyMask, &ft_on_destroy, data);
	mlx_loop(data->mlx);
	ft_free_game(data);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (initialize_and_configure_game(ac, av, &data) != 0)
		return (1);
	ft_iterate_map_and_put_images(&data);
	event_loop_and_cleanup(&data);
	return (0);
}
