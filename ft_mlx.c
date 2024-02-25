/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:56:31 by awacowsk          #+#    #+#             */
/*   Updated: 2023/12/05 17:56:32 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	//ft_free_game(data);
	exit(0);
	return (0);
}

void	ft_mlx_xpm_file_to_image(t_game *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, 
			"./textures/1.xpm", &data->w, &data->h);
	data->img2 = mlx_xpm_file_to_image(data->mlx, 
			"./textures/0.xpm", &data->w, &data->h);
	data->img3 = mlx_xpm_file_to_image(data->mlx, 
			"./textures/P.xpm", &data->w, &data->h);
	data->img4 = mlx_xpm_file_to_image(data->mlx, 
			"./textures/C.xpm", &data->w, &data->h);
	data->img5 = mlx_xpm_file_to_image(data->mlx, 
			"./textures/E.xpm", &data->w, &data->h);
}

void	ft_iterate_map_and_put_images(t_game *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (size_t)data->h)
	{
		j = 0;
		while (j < (size_t)data->w)
		{
			ft_put_image_to_window(data, i, j);
			j++;
		}
		i++;
	}
}

void	ft_put_image_to_window(t_game *data, size_t i, size_t j)
{
	int		x;
	int		y;

	x = j * 64;
	y = i * 64;
	if (data->map[i][j].value)
	{
		if (data->map[i][j].value == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
		else if (data->map[i][j].value == '0')
			mlx_put_image_to_window(data->mlx, data->win, data->img2, x, y);
		else if (data->map[i][j].value == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->img3, x, y);
		else if (data->map[i][j].value == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->img4, x, y);
		else if (data->map[i][j].value == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->img5, x, y);
	}
}
