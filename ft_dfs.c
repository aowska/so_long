/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:33:10 by awacowsk          #+#    #+#             */
/*   Updated: 2024/02/24 21:33:10 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_so_long.h"

bool	ft_dfs(t_node *node, size_t RowAmount, 
			size_t firstRowLength, t_node **nodes)
{
	if (node->visited || node->value == '1' 
		|| node->i >= RowAmount || node->j >= firstRowLength)
		return (false);
	node->visited = true;
	if (node->value == 'E') 
		return (true);
	return (ft_dfs(&nodes[node->i + 1][node->j],
		RowAmount, firstRowLength, nodes) ||
		ft_dfs(&nodes[node->i - 1][node->j],
		RowAmount, firstRowLength, nodes) ||
		ft_dfs(&nodes[node->i][node->j + 1],
		RowAmount, firstRowLength, nodes) ||
		ft_dfs(&nodes[node->i][node->j - 1],
		RowAmount, firstRowLength, nodes));
}

t_node	**ft_allocate_map(t_game *data)
{
	int		i;

	data->map = (t_node **)malloc(sizeof(t_node *)
			* ((int)data->h + 1));
	if (data->map == NULL)
	{
		ft_printf("Malloc Failed\n");
		return (NULL);
	}
	i = 0;
	while (i < data->h)
	{
		data->map[i] = (t_node *)malloc(sizeof(t_node) 
				* ((int)data->w + 1));
		if (data->map[i] == NULL)
		{
			ft_printf("Malloc Failed\n");
			return (NULL);
		}
		i++;
	}
	return (data->map);
}

void	ft_initialize_map(char **maps, t_game *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			data->map[i][j].visited = false;
			data->map[i][j].value = maps[i][j];
			data->map[i][j].i = i;
			data->map[i][j].j = j;
			if (data->map[i][j].value == 'P')
			{
				data->player_x = i;
				data->player_y = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_pre_dfs(char **maps, t_game *data)
{
	t_node	*start_node;

	start_node = NULL;
	data->map = ft_allocate_map(data);
	if (data->map == NULL)
		return (1);
	ft_initialize_map(maps, data);
	start_node = &data->map[data->player_x][data->player_y];
	if (!ft_dfs(start_node, data->h, data->w, data->map))
	{
		ft_printf(ERR_PATH);
		return (1);
	}
	return (0);
}
