/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:56:31 by awacowsk          #+#    #+#             */
/*   Updated: 2024/02/04 16:38:24 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

int	ft_map(const char *filename)
{
	char	**line;
	int		count;

	count = 0;
	if (ft_strstr(filename, ".ber") == NULL)
		return (ft_printf(ERR_EXT), 1);
	line = ft_read_map(filename, &count);
	if (line == NULL)
		return (ft_printf(ERR_EMPTY), 1);
	if (ft_maps_errors(line, count) != 0) 
		return (ft_free_map(line, count), 1);
	ft_pre_dfs(line, count);
	ft_free_map(line, count);
	return (0);
}

char	**ft_read_map(const char *filename, int *count)
{
	int		fd;
	char	**line;
	char	*s;

	fd = open(filename, O_RDONLY);
	if (fd == -1) 
		return (ft_printf(ERR_OPEN), NULL);
	while ((s = get_next_line(fd)) != NULL)
		(*count)++;
	close(fd);
	fd = open(filename, O_RDONLY);
	line = (char **)malloc(sizeof(char *) * (*count));
	if (line == NULL) 
		return (close(fd), ft_printf("Memory allocation failed\n"), NULL);
	(*count) = 0;
	//s = get_next_line(fd);
	while ((s = get_next_line(fd)) != NULL) 
	{
		line[(*count)] = s;
		printf( "%s", line[(*count)]);
		(*count)++;
	}
	close(fd);
	return (line);
}

void	ft_free_map(char **map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

bool	ft_dfs(Node *node, Node nodes[][100], 
		size_t RowAmount, size_t firstRowLength)
{
	if (node->visited || node->value == '1' 
		|| node->i >= RowAmount || node->j >= firstRowLength)
		return (false);
	node->visited = true;
	if (node->value == 'M') 
		return (true);
	return (ft_dfs(&nodes[node->i + 1][node->j], 
		nodes, RowAmount, firstRowLength) ||
		ft_dfs(&nodes[node->i - 1][node->j], 
		nodes, RowAmount, firstRowLength) ||
		ft_dfs(&nodes[node->i][node->j + 1], 
		nodes, RowAmount, firstRowLength) ||
		ft_dfs(&nodes[node->i][node->j - 1], 
		nodes, RowAmount, firstRowLength));
}

int	ft_pre_dfs(char **map, size_t row_amount)
{
	size_t	first_row_length;
	Node	nodes[row_amount][100];
	Node	*start_node;
	size_t	i;
	size_t	j;

	i = 0;
	first_row_length = ft_strlen(map[0]) - 1;
	start_node = NULL;
	while (i < row_amount) 
	{
		j = 0;
		while (j < first_row_length) 
		{
			nodes[i][j].visited = false;
			nodes[i][j].value = map[i][j];
			nodes[i][j].i = i;
			nodes[i][j].j = j;
			if (nodes[i][j].value == 'P')
				start_node = &nodes[i][j];
			j++;
		}
		i++;
	}
	if (ft_dfs(start_node, nodes, row_amount, first_row_length) == 1)
		return (ft_printf(ERR_PATH), 1);
	return (0);
}

int	ft_maps_errors(char **map, size_t e)
{
	size_t	first_row_length;
	size_t	i;

	i = 0;
	first_row_length = ft_strlen(map[0]);
	if (ft_maps_errors_2(map, i, first_row_length, e) != 0)
		return (1);
	while (i < (first_row_length - 1))
	{
		if (map[0][i] != '1' || map[e - 1][i] != '1')
			return (ft_printf(ERR_WALL), 1);
		i++;
	}
	return (0);
}

int	ft_maps_errors_2(char **map, size_t i, size_t row_length, size_t e)
{
	int	found_p;
	int	found_e;

	found_p = 0;
	found_e = 0;
	while (i < e)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			return (ft_printf(ERR_WIDTH), 1);
		else if (ft_strlen(map[i]) != row_length)
			return (ft_printf(ERR_WALL), 1);
		else if (ft_char_check(map) != 0)
			return (ft_printf(ERR_CHAR), 1);
		else if (ft_strchr(map[i], 'E') != NULL)
			found_e++;
		else if (ft_strchr(map[i], 'P') != NULL)
			found_p++;
		i++;
	}
	if (ft_check_exit_and_player(&found_e, &found_p) == 1)
		return (1);
	return (0);
}

int	ft_check_exit_and_player(int *found_e, int *found_p)
{
	if (*found_e > 1)
		return (ft_printf(ERR_DUP_E), 1);
	else if (*found_p > 1) 
		return (ft_printf(ERR_DUP_E), 1);
	else if (*found_e == 0)
		return (ft_printf(ERR_NO_E), 1);
	else if (*found_p == 0)
		return (ft_printf(ERR_NO_P), 1);
	return (0);
}

int	ft_char_check(char **map)
{
	while (*map) 
	{
		char *row = *map;
		while (*row)
		{
			if (*row != '1' && *row != '0' && *row != 'P' 
				&& *row != 'E' && *row != 'C'  && *row != '\0' && *row != '\n')
				return (1);
			row++;
		}
		map++;
	}
	return (0);
}
