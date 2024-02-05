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

typedef struct s_data
{
	void *mlx;
	void *win;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main (int ac, char **av)
{
	t_data data;

	if (ac != 2)
		return(ft_printf(ERR_ARG), 0);
	if(ft_map(av[1]) != 0)
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
    data.win = mlx_new_window(data.mlx, 800, 600, "SO_LONG");
	if (!data.win)
		return (free(data.mlx), 1);
	// Register key release hook
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}
