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
# include "./minilibx_opengl_20191021/mlx.h"


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
 
  int    ft_map();
 char    *get_next_line(int fd);

#endif
