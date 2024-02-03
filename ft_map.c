/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:56:31 by awacowsk          #+#    #+#             */
/*   Updated: 2023/12/05 17:56:32 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Dodaj brakujący nagłówek dla funkcji malloc i free
#include "./ft_so_long.h"

bool ft_dfs(Node *node, Node nodes[][100], size_t RowAmount, size_t firstRowLength);
int ft_pre_dfs(char **map, size_t RowAmount);
int ft_maps_errors(char **map, size_t e);
char** ft_read_map(const char *filename, int *count);
void ft_free_map(char **map, int count);

int ft_map(char *file) 
{
    char **line;
    int count;

    count = 0;
    if (ft_strstr(filename, ".ber") == NULL)
        return(ft_printf(ERR_EXT), 1)
    line = ft_read_map(file, &count);
    if (line == NULL)
    {
        ft_printf(ERR_EMPTY);
        return (1);
    }
    if (ft_maps_errors(line, count) != 1) 
    {
        printf("wrong\n");
        ft_free_map(line, count);
        return 1;
    }
    ft_pre_dfs(line, count);
    ft_free_map(line, count);
    return 0;
}

char** ft_read_map(const char *filename, int *count)
{
    int fd;
    char **line;
    char *s;

    fd = open(filename, O_RDONLY);
    if (fd == -1) 
    {
        printf(ERR_OPEN);
        return NULL;
    }
    while ((s = get_next_line(fd)) != NULL) 
        (*count)++;
    lseek(fd, 0, SEEK_SET);
    line = (char **)malloc(sizeof(char *) * (*count));
    if (line == NULL) 
    {
        printf("Memory allocation failed\n");
        close(fd);
        return NULL;
    }
    (*count) = 0;
    while ((s = get_next_line(fd)) != NULL) 
    {
        line[(*count)] = s;
        (*count)++;
    }
    close(fd);
    return (line);
}

void ft_free_map(char **map, int count) 
{
    for (int i = 0; i < count; i++) 
        free(map[i]);
    free(map);
}

bool ft_dfs(Node *node, Node nodes[][100], size_t RowAmount, size_t firstRowLength)
{
    if (node->visited || node->value == '1' || node->i >= RowAmount || node->j >= firstRowLength)
        return false;
    node->visited = true;
    if (node->value == 'M') 
        return true;
    return (ft_dfs(&nodes[node->i + 1][node->j], nodes, RowAmount, firstRowLength) ||
           ft_dfs(&nodes[node->i - 1][node->j], nodes, RowAmount, firstRowLength) ||
           ft_dfs(&nodes[node->i][node->j + 1], nodes, RowAmount, firstRowLength) ||
           ft_dfs(&nodes[node->i][node->j - 1], nodes, RowAmount, firstRowLength));
}

int ft_pre_dfs(char **map, size_t RowAmount) 
{
    size_t firstRowLength;
    Node nodes[RowAmount][100];
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    firstRowLength = ft_strlen(map[0]) - 1;
    while (i < RowAmount) 
    {
        j = 0;
        while (j < firstRowLength) 
        {
            nodes[i][j].visited = false;
            nodes[i][j].value = map[i][j];
            nodes[i][j].i = i;
            nodes[i][j].j = j;
            printf("%c", nodes[i][j].value);
            j++;
        }
        printf("\n");
        i++;
    }
    Node *startNode = NULL;
    i = 0;
    while (i < RowAmount && startNode == NULL) 
    {
        j = 0;
        while (j < firstRowLength && startNode == NULL) 
        {
            if (nodes[i][j].value == 'P')
            {
                startNode = &nodes[i][j];
                break;
            }
            j++;
        }
        i++;
    }
    if (startNode != NULL) 
    {
        bool pathExists = ft_dfs(startNode, nodes, RowAmount, firstRowLength);
        if(pathExists == FALSE)
            ft_printf(ERR_PATH);
    } 
    else 
        printf(ERR_NO_P);
    return (0);
}

int ft_maps_errors(char **map, size_t e) 
{
    size_t firstRowLength;
    int found_E;
    int found_P;
    size_t i;

    i = 0;
    firstRowLength = ft_strlen(map[0]);
    found_E = 0;
    found_P = 0;
    if(ft_maps_errors_2(map, i, firstRowLength) != 0)
        return 
    while (i < (firstRowLength - 1)) 
    {
        if (map[0][i] != '1' || map[e - 1][i] != '1')
            return (ERR_WALL);
        i++;
    }
    if (found_E > 1)
        return(ft_printf(ERR_DUP_E), 2);
    else if (found_P > 1) 
        return (ft_printf(ERR_DUP_E), 2);
    else if (found_E == 0)
        return(ft_printf(ERR_NO_E), 2)
    return (1);
}
int ft_maps_errors_2(har **map, size_t i, size_t firstRowLength)
{
    while (i < e) 
        {
            if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
                return (ft_printf(ERR_WIDTH), 2);
            else if (ft_strlen(map[i]) != firstRowLength)
                return (ft_printf(ERR_WALL), 2);
            else if (ft_char_check(map) == 1)
                return (ft_printf(ERR_CHAR), 2);
            else if (ft_strchr(map[i], 'E') != NULL)
                found_E++;
            else if (ft_strchr(map[i], 'P') != NULL)
                found_P++;
            i++;
        }
        return (0);
}

