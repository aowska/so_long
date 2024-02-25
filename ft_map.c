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

	count = 0;
	if (ft_strstr(filename, ".ber") == NULL)
		return (ft_printf(ERR_EXT), 1);
	line = ft_read_map(filename, &count);
	if (line == NULL)
		return (ft_printf(ERR_EMPTY), 1);
	data->h = count;
	if (ft_maps_errors(line, count, data) != 0) 
		return (ft_free_map(line), 1);
	if (ft_pre_dfs(line, data) != 0)
		return (ft_free_map(line), 1);
	ft_free_map(line);
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

char	**ft_read_map(const char *filename, int *count)
{
	int		fd;
	char	**line;
	int		i;

	fd = 0;
	ft_check_amount_lines(count, fd, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) 
		return (ft_printf(ERR_OPEN), NULL);
	line = (char **)malloc(sizeof(char *) * ((*count) + 1));
	if (line == NULL) 
		return (close(fd), ft_printf("Malloc Faild\n"), NULL);
	i = 0;
	while (i < (*count))
	{
		line[i] = get_next_line(fd);
		if (!line[i])
			break ;
		if (!(ft_strchr(line[i], '\n')))
			line[i] = ft_strjoin(line[i], "\n\0");
		ft_printf("%s", line[i]);
		i++;
	}
	line[i] = NULL;
	return (close(fd), line);
}
