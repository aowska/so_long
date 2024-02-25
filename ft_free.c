/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:45:28 by awacowsk          #+#    #+#             */
/*   Updated: 2024/02/24 20:11:49 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

/*for ft_map.c*/
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (*map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*for main.c */
void	ft_free_game_map(t_node **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while ((map[i]) != NULL)
		{
				free(map[i]);
				map[i] = NULL;
			i++;
		}
		free(map);
	}
}

void	ft_free_game_resources_1(t_game *game)
{
	if (game->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
	if (game->img2 != NULL)
	{
		mlx_destroy_image(game->mlx, game->img2);
		game->img2 = NULL;
	}
	if (game->img3 != NULL)
	{
		mlx_destroy_image(game->mlx, game->img3);
		game->img3 = NULL;
	}
}

void	ft_free_game_resources_2(t_game *game)
{
	if (game->img4 != NULL)
	{
		mlx_destroy_image(game->mlx, game->img4);
		game->img4 = NULL;
	}
	if (game->img5 != NULL)
	{
		mlx_destroy_image(game->mlx, game->img5);
		game->img5 = NULL;
	}
}

void	ft_free_game(t_game *game)
{
	if (game == NULL)
		return ;
	ft_free_game_map(game->map);
	ft_free_game_resources_1(game);
	ft_free_game_resources_2(game);
	free(game->mlx);
}
