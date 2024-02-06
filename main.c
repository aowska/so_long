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

typedef struct position
{
	int x;
	int y;
} t_pos;


typedef struct game
{
	void *mlx;
	void *win;
} t_game;

void	setting_img(t_game game)
{
	int		h;
	int		w;

	hei = 0;
	while (hei < game.height)
	{
		wid = 0;
		while (wid < game.width)
		{
			if (game.str_line[hei * game.width + wid] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.wall, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'C')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.chest, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.chara, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.width + wid] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.rune, wid * 64, hei * 64);
			}
			else
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.land, wid * 64, hei * 64);
			}
			wid++;
		}
		hei++;
	}
}
 
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



void ft_mlx_xpm_file_to_image(void *mlx)
{
	int img_height = 64;
	int img_w = 64;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	
	img = mlx_xpm_file_to_image(data.mlx, "./textures/1.xpm", &img_w, &img_height);
	img2 = mlx_xpm_file_to_image(data.mlx, "./textures/0.xpm", &img_w, &img_height);
	img3 = mlx_xpm_file_to_image(data.mlx, "./textures/P.xpm", &img_w, &img_height);
	img4 = mlx_xpm_file_to_image(data.mlx, "./textures/C.xpm", &img_w, &img_height);
	img5 = mlx_xpm_file_to_image(data.mlx, "./textures/E.xpm", &img_w, &img_height);
	ft_mlx_put_image_to_window

}

int main (int ac, char **av)
{
	t_game data;
	


	if (ac != 2)
		return(ft_printf(ERR_ARG), 0);
	if(ft_map(av[1]) != 0)
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "SO_LONG");
	if (!data.win)
		return (free(data.mlx), 1);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	ft_mlx_xpm_file_to_image(data.mlx);
	ft_mlx_put_image_to_window
	mlx_put_image_to_window(data.mlx, data.win, img, data.x * 64, data.y * 64);
	mlx_put_image_to_window(data.mlx, data.win, img2,0 * 64, 1 * 64);
	mlx_put_image_to_window(data.mlx, data.win, img3, 0 * 64, 0  * 64);
	mlx_put_image_to_window(data.mlx, data.win, img4, 0 * 64, 2 * 64);
	mlx_put_image_to_window(data.mlx, data.win, img5, 0 * 64, 3 *  64);
	mlx_loop(data.mlx);
	return (0);
}
