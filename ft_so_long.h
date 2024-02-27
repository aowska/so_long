/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:56:23 by awacowsk          #+#    #+#             */
/*   Updated: 2023/12/05 17:56:26 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"

# define KEY_ESC	65307
# define KEY_W		97
# define KEY_A		119
# define KEY_S		100
# define KEY_D		115
# define MAP_EXT	".ber"
# define ERR_ARG	"Error\nWrong number of arguments: requires 1."
# define ERR_EXT	"Error\nWrong file format, maps must have extension 'ber'."
# define ERR_OPEN	"Error\nFailed to open map"
# define ERR_EMPTY	"Error\nFile is empty."
# define ERR_CHAR	"Error\nInvalid map: invalid character."
# define ERR_WIDTH	"Error\nInvalid map: not a rectangle."
# define ERR_NO_P	"Error\nInvalid map: missing starting player position."
# define ERR_DUP_P	"Error\nInvalid map: more than one starting player position."
# define ERR_NO_E	"Error\nInvalid map: missing exit."
# define ERR_DUP_E	"Error\nInvalid map: more than one exit."
# define ERR_NO_C	"Error\nInvalid map: there are no collectibles."
# define ERR_WALL	"Error\nInvalid map: wall does not enclose the map."
# define ERR_PATH	"Error\nInvalid map: there is no valid path."

# define PIC_WALL	"./textures/1.xpm"  
# define PIC_BACK	"./textures/0.xpm"
# define PIC_P		"./textures/P1.xpm"
# define PIC_C		"./textures/C.xpm"
# define PIC_E		"./textures/E.xpm"
# define WIDTH		600
# define HEIGHT		300

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// Struktura reprezentująca węzeł grafu
typedef struct Node {
	bool	visited;
	char	value;
	size_t	i;
	size_t	j;
}	t_node;

typedef struct game {
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		player_x;
	int		player_y;
	int		moves;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	t_node	**map;
}	t_game;

int		ft_check_p_e_c(char **map, size_t i, size_t row_length, size_t e);
int		ft_check_player_exit_coll(int *found_p, int *found_e, int *found_c);
int		ft_check_exit_and_player(int *found_e, int *found_p, int *found_c);
int		ft_char_check(char **map);
char	*get_next_line(int fd);
bool	ft_dfs(t_node *node, size_t RowAmount,
			size_t	firstRowLength, t_node **nodes);
t_node	**ft_allocate_map(t_game *data);
void	ft_initialize_map(char **maps, t_game *data);
int		ft_pre_dfs(char **map, t_game *data);
int		ft_check_map_errors(char **map, size_t i, size_t row_length, size_t e);
int		ft_maps_errors(char **map, size_t e, t_game *data);
void	ft_check_amount_lines(int *count, int fd, const char *filename);
char	**ft_read_map(const char *filename, int *count, int i);
void	ft_free_map(char ***map);
int		ft_map(const char *filename, t_game *data);
void	ft_free_game_map(t_node **map);
void	ft_free_game_resources_1(t_game *game);
void	ft_free_game_resources_2(t_game *game);
void	ft_free_game(t_game *game);
int		ft_on_destroy(t_game *data);
void	ft_mlx_xpm_file_to_image(t_game *data);
void	ft_put_image_to_window(t_game *data, size_t i, size_t j);
void	ft_iterate_map_and_put_images(t_game *data);
bool	ft_can_move_to_destination(int x, int y, t_game *data);
void	ft_move_player(int new_x, int new_y, t_game *data);
void	ft_handle_special_keys(int key, t_game *data);
int		ft_key_hook(int key, t_game *data);

#endif
