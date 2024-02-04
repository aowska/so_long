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
# include	"./Lmlx/mlx.h"
# include	"./Lmlx/mlx_int.h"


# define C_PLAYER	'P'
# define C_EXIT		'E'
# define C_COLLECT	'C'
# define C_WALL		'1'
# define C_FLOOR	'0'
# define MAP_EXT	".ber" //checkkkkk
# define ERR_MSG	"Error"
# define ERR_ARG	"Wrong number of arguments: requires 1 (map file path)." //done 
# define ERR_EXT	"Wrong file format, maps must have extension 'ber'." //done 
# define ERR_OPEN	"Failed to open map"  //(done) 
# define ERR_EMPTY	"File is empty." //done
# define ERR_CHAR	"Invalid map: invalid character." //Checkkkkk
# define ERR_WIDTH	"Invalid map: not a rectangle." //done 
# define ERR_NO_P	"Invalid map: missing starting player position."  //done
# define ERR_DUP_P	"Invalid map: more than one starting player position." //done 
# define ERR_NO_E	"Invalid map: missing exit." //done 
# define ERR_DUP_E	"Invalid map: more than one exit." //done
# define ERR_NO_C	"Invalid map: there are no collectibles."
# define ERR_WALL	"Invalid map: wall does not enclose the map." //done 
# define ERR_PATH	"Invalid map: there is no valid path." //done

#  define PIC_WALL              "./pics/wall.png"  
#  define PIC_BACK              "./pics/Back.png"
#  define PIC_P                 "./pics/WE.png"
#  define PIC_C                 "./pics/drink.png"
#  define PIC_EXIT              "./pics/goal.png"
# define  WIDTH 800
# define  HEIGHT  600

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

// Struktura reprezentująca węzeł grafu
typedef struct Node {
    bool visited;            // Czy węzeł został odwiedzony
    char value;             // Wartość węzła: "M", "P", "1", "0"
    size_t i; // Tablica wskaźników na sąsiadujące węzły
    size_t j;   // Liczba sąsiadujących węzłów
} Node;

int     ft_check_exit_and_player(int *found_E, int *found_P);
int     ft_char_check(char **map);
int     ft_map();
char    *get_next_line(int fd);
bool    ft_dfs(Node *node, Node nodes[][100], size_t RowAmount, size_t firstRowLength);
int     ft_pre_dfs(char **map, size_t RowAmount);
int     ft_maps_errors_2(char **map, size_t i, size_t firstRowLength, size_t e);
int     ft_maps_errors(char **map, size_t e);
char**  ft_read_map(const char *filename, int *count);
void    ft_free_map(char **map, int count);

#endif
