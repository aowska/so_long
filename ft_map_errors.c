/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:48:38 by awacowsk          #+#    #+#             */
/*   Updated: 2024/02/24 19:48:39 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_check_map_errors(char **map, size_t i, size_t row_length, size_t e)
{
	int	result;

	result = 0;
	while (i < e)
	{
		if (ft_strlen(map[i]) != row_length)
			return (ft_printf(ERR_WIDTH), 1);
		if (map[i][0] != '1' || map[i][row_length - 2] != '1')
			return (ft_printf(ERR_WALL), 1);
		if (ft_char_check(map) != 0)
			return (ft_printf(ERR_CHAR), 1);
		i++;
	}
	i = 0;
	result = ft_check_p_e_c(map, i, row_length, e);
	return (result);
}

int	ft_check_p_e_c(char **map, size_t i, size_t row_length, size_t e)
{
	int		found_p;
	int		found_e;
	int		found_c;
	size_t	j;

	found_p = 0;
	found_e = 0;
	found_c = 0;
	while (i < e)
	{
		j = 0;
		while (j < row_length)
		{
			if (map[i][j] == 'E')
				found_e++;
			else if (map[i][j] == 'P')
				found_p++;
			else if (map[i][j] == 'C')
				found_c++;
			j++;
		}
		i++;
	}
	return (ft_check_player_exit_coll(&found_p, &found_e, &found_c));
}

int	ft_check_player_exit_coll(int *found_p, int *found_e, int *found_c)
{
	if (ft_check_exit_and_player(found_e, found_p, found_c) == 1)
		return (1);
	return (0);
}

int	ft_check_exit_and_player(int *found_e, int *found_p, int *found_c)
{
	if (*found_e > 1)
		return (ft_printf(ERR_DUP_E), 1);
	else if (*found_p > 1) 
		return (ft_printf(ERR_DUP_P), 1);
	else if (*found_e == 0)
		return (ft_printf(ERR_NO_E), 1);
	else if (*found_p == 0)
		return (ft_printf(ERR_NO_P), 1);
	else if (*found_c == 0)
		return (ft_printf(ERR_NO_C), 1);
	return (0);
}

int	ft_char_check(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL) 
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' 
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
