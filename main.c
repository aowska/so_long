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

int on_destroy(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
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

/*void ft_mlx_put_image_to_window(t_game *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->map->x * 64, data->map.y * 64);
	mlx_put_image_to_window(data.mlx, data.win, data.img2,0 * 64, 1 * 64);
	mlx_put_image_to_window(data.mlx, data.win, data.img3, 0 * 64, 0  * 64);
	mlx_put_image_to_window(data.mlx, data.win, data.img4, 0 * 64, 2 * 64);
	mlx_put_image_to_window(data.mlx, data.win, data.img5, 0 * 64, 3 *  64);
}*/ 

int main (int ac, char **av)
{
	t_game data;
	
	if (ac != 2)
		return(ft_printf(ERR_ARG), 0);
	ft_game_initialization(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error: mlx is not initialized\n"), 1);
	if(ft_map(av[1], &data) != 0)
		return (1);
	ft_printf("%d", data.w);
	ft_printf("%d", data.h);
    //data.win = mlx_new_window(data.mlx, data.w * 32, data.h * 32, "so_long");
	//if (!data.win)
	//	return (free(data.mlx), 1);
	//mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	//mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	//ft_mlx_xpm_file_to_image(&data);
	//ft_mlx_put_image_to_window(&data);
	
	/* mlx_expose_hook(win1,expose_win1,0);
  	mlx_mouse_hook(data.win,mouse_win1,0);
  mlx_key_hook(win1,key_win1,0);
  mlx_expose_hook(win2,expose_win2,0);
  mlx_mouse_hook(win2,mouse_win2,0);
  mlx_key_hook(win2,key_win2,0);
  mlx_key_hook(win3,key_win3,0);*/

	mlx_loop(data.mlx);
	return (0);
}
