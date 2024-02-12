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

# include	<stdarg.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<stdio.h>
# include	<errno.h>
# include	<stdbool.h>
# include	"./Libft/libft.h"
# include	"./Libft/ft_printf.h"
# include	"./mlx/mlx.h"
# include	"./mlx/mlx_int.h"


# define C_PLAYER	'P'
# define C_EXIT		'E'
# define C_COLLECT	'C'
# define C_WALL		'1'
# define C_FLOOR	'0'
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define MAP_EXT	".ber"
# define ERR_MSG	"Error"
# define ERR_ARG	"Wrong number of arguments: requires 1 (map file path)."
# define ERR_EXT	"Wrong file format, maps must have extension 'ber'."
# define ERR_OPEN	"Failed to open map"
# define ERR_EMPTY	"File is empty."
# define ERR_CHAR	"Invalid map: invalid character."
# define ERR_WIDTH	"Invalid map: not a rectangle."
# define ERR_NO_P	"Invalid map: missing starting player position."
# define ERR_DUP_P	"Invalid map: more than one starting player position."
# define ERR_NO_E	"Invalid map: missing exit."
# define ERR_DUP_E	"Invalid map: more than one exit."
# define ERR_NO_C	"Invalid map: there are no collectibles."
# define ERR_WALL	"Invalid map: wall does not enclose the map."
# define ERR_PATH	"Invalid map: there is no valid path."

# define PIC_WALL   "./textures/1.xpm"  
# define PIC_BACK   "./textures/0.xpm"
# define PIC_P      "./textures/P.xpm"
# define PIC_C      "./textures/C.xpm"
# define PIC_E      "./textures/E.xpm"
# define WIDTH      600
# define HEIGHT     300

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// Struktura reprezentująca węzeł grafu
typedef struct Node {
    bool visited;            // Czy węzeł został odwiedzony
    char value;             // Wartość węzła: "M", "P", "1", "0"
    size_t i; // Tablica wskaźników na sąsiadujące węzły
    size_t j;   // Liczba sąsiadujących węzłów
} Node;

typedef struct game {
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	void    *img;
	void    *img2;
	void    *img3;
	void    *img4;
	void    *img5;
	Node    **map;
} t_game;

int     ft_check_exit_and_player(int *found_E, int *found_P);
int     ft_char_check(char **map);
char    *get_next_line(int fd);
bool    ft_dfs(Node *node, size_t RowAmount, size_t firstRowLength, Node **nodes);
int     ft_pre_dfs(char **map, size_t RowAmount, t_game *data);
int     ft_maps_errors_2(char **map, size_t i, size_t firstRowLength, size_t e);
int     ft_maps_errors(char **map, size_t e, t_game *data);
char**  ft_read_map(const char *filename, int *count);
void    ft_free_map(char **map, int count);
int     ft_map(const char *filename, t_game *data);

#endif
