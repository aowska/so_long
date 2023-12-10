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
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include "./Libft/libft.h"
# include "./minilibx_mms_20200219/mlx.h"
# include "./ft_printf/ft_printf.h"



#  define ERROR_E               "ERROR: NO EXIT"
#  define ERROR_C               "ERROR: NO DRINKS"
#  define ERROR_P               "ERROR: NO PLAYER"
#  define ERROR_RECTANGULAR     "ERROR: MAP INVALID"
#  define ERROR_WALL            "ERROR: WALL INVALID"
#  define ERROR_PATH            "ERROR: PATH INVALID"
#  define ERROR_ARG             "ERROR: INVALID AGUMENT"

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
    char *value;             // Wartość węzła: "M", "P", "1", "0"
    struct Node **neighbors; // Tablica wskaźników na sąsiadujące węzły
    size_t neighbor_count;   // Liczba sąsiadujących węzłów
} Node;
 
 char    *get_next_line(int fd);

#endif