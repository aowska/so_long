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

int	ft_map(const char *filename, t_game *data)
{
	char	**line;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (ft_strstr(filename, ".ber") == NULL)
		return (ft_printf(ERR_EXT), 1);
	line = ft_read_map(filename, &count, i);
	if (line == NULL)
		return (ft_printf(ERR_EMPTY), 1);
	data->h = count;
	if (ft_maps_errors(line, count, data) != 0) 
		return (ft_free_map(&line), 1);
	if (ft_pre_dfs(line, data) != 0)
		return (ft_free_map(&line), 1);
	ft_free_map(&line);
	return (0);
}

int	ft_maps_errors(char **map, size_t e, t_game *data)
{
	size_t	first_row_length;
	size_t	i;

	i = 0;
	first_row_length = 0;
	first_row_length = ft_strlen(map[0]);
	if (ft_check_map_errors(map, i, first_row_length, e) != 0)
		return (1);
	while (i < (first_row_length - 1))
	{
		if (map[0][i] != '1' || map[e - 1][i] != '1')
			return (ft_printf(ERR_WALL), 1);
		i++;
	}
	data->w = first_row_length - 1;
	return (0);
}

void	ft_check_amount_lines(int *count, int fd, const char *filename)
{
	char	*s;

	s = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1) 
		return ;
	s = get_next_line(fd);
	while (s != NULL)
	{
		(*count)++;
		if (!s)
			break ;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

char	**ft_read_map(const char *filename, int *count, int i)
{
	int		fd;
	char	**line;
	char	*temp;

	fd = 0;
	ft_check_amount_lines(count, fd, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) 
		return (ft_printf(ERR_OPEN), NULL);
	line = (char **)malloc(sizeof(char *) * ((*count) + 1));
	if (line == NULL) 
		return (close(fd), ft_printf("Malloc Faild\n"), NULL);
	while (i < (*count))
	{
		line[i] = get_next_line(fd);
		if (!(ft_strchr(line[i], '\n')))
		{
			temp = ft_strjoin(line[i], "\n\0");
			free(line[i]);
			line[i] = temp;
		}
		i++;
	}
	return (line[i] = NULL, close(fd), line);
}
