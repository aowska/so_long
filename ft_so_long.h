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

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>

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

#endif