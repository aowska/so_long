/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:45:43 by awacowsk          #+#    #+#             */
/*   Updated: 2024/02/24 19:45:44 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

bool	ft_can_move_to_destination(int x, int y, t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->map[x][y].value == 'E')
	{
		while (i < data->h)
		{
			j = 0;
			while (j < data->w)
			{
				if (data->map[i][j].value == 'C')
					return (false);
				j++;
			}
			i++;
		}
		mlx_hook(data->win, DestroyNotify, 
			StructureNotifyMask, &ft_on_destroy, data);
		ft_free_game(data);
		exit(EXIT_SUCCESS);
		return (true);
	}
	return (data->map[x][y].value != '1');
}

void	ft_move_player(int new_x, int new_y, t_game *data)
{
	data->map[data->player_x][data->player_y].value = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[data->player_x][data->player_y].value = 'P';
	data->moves++;
	ft_printf("Moves %d\n", data->moves);
}

void	ft_handle_special_keys(int key, t_game *data)
{
	if (key == KEY_ESC)
	{
		mlx_hook(data->win, DestroyNotify, 
			StructureNotifyMask, &ft_on_destroy, data);
		ft_free_game(data);
		exit(EXIT_SUCCESS);
	}
}

int	ft_key_hook(int key, t_game *data)
{
	ft_handle_special_keys(key, data);
	if (key == KEY_W && 
		ft_can_move_to_destination(data->player_x, data->player_y - 1, data))
		ft_move_player(data->player_x, data->player_y - 1, data);
	else if (key == KEY_S && 
		ft_can_move_to_destination(data->player_x, data->player_y + 1, data))
		ft_move_player(data->player_x, data->player_y + 1, data);
	else if (key == KEY_A && 
		ft_can_move_to_destination(data->player_x - 1, data->player_y, data))
		ft_move_player(data->player_x - 1, data->player_y, data);
	else if (key == KEY_D && 
		ft_can_move_to_destination(data->player_x + 1, data->player_y, data))
		ft_move_player(data->player_x + 1, data->player_y, data);
	ft_iterate_map_and_put_images(data);
	return (0);
}
