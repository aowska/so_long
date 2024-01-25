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
# include "./ft_so_long.h"

Node ** nodes[100][100];

bool ft_dfs(Node *node) 
{
    printf("%c\n", node->value );
    printf("%d\n", node->visited);
    if (node->visited)
        return false;
    node->visited = true;
    if (node->value == 'M')
        return true;
    if (node->value == '1')
        return false;
    if(ft_dfs((&nodes[node->i + 1][node->j])))
        return true;
    if(ft_dfs((&nodes[node->i - 1][node->j])))
        return true;
    if(ft_dfs((&nodes[node->i ][node->j + 1])))
        return true;
    if(ft_dfs((&nodes[node->i][node->j - 1])))
        return true;
    return false;
}
int ft_pre_dfs(char **map, size_t RowAmount)
{
    size_t firstRowLength = ft_strlen(map[0]) - 1;
   // nodes[RowAmount][firstRowLength]; // Tworzymy macierz węzłów
    size_t i = 0;
    size_t j = 0; 
    while (i < RowAmount) 
    {
        j = 0; 
        while (j < firstRowLength) 
        {
            nodes[i][j].visited = false; // Ustawiamy początkowy stan odwiedzin na false
            nodes[i][j].value = map[i][j]; // Przypisujemy wartość węzła
            // Tworzymy dla każdego węzła tablicę sąsiadujących węzłów (początkowo pustą)
            nodes[i][j].i = i; 
            nodes[i][j].j = j; 
            printf("%c",nodes[i][j].value);
            j++;
        }
        printf("\n");
        i++;
    }
    // Wyszukujemy węzła startowego (P) na mapie
    Node *startNode = NULL;
    i = 0;
    while (i < RowAmount && startNode == NULL) 
    {
        j = 0;
       // printf("%c\n", nodes[i][j].value);
         while (j < firstRowLength && startNode == NULL) 
        {
                if (strcmp(&nodes[i][j].value, "P") == 0)
                {
                    startNode = &nodes[i][j]; 
                    break ;
                }
            j++;
        }
        i++;
    }
    //printf("%c\n", startNode->value);
    // Sprawdzamy, czy znaleziono węzeł startowy
    if (startNode != NULL) 
    {
        bool pathExists = ft_dfs(startNode);
        if (pathExists)
            printf("CAN from  P to M.\n");
        else 
            printf("CAN NOT from P TO M.\n");
    }
    else
        printf("P is not find\n");
    return 0; 
}

int ft_maps_errors(char **map, size_t e)
{
    size_t firstRowLength = ft_strlen(map[0]); // Długość pierwszego wiersza
    int found_M = 0, found_P = 0;
    // Sprawdzenie pierwszego i ostatniego wiersza
    size_t  i = 0;
    while (i < e) 
    {
        if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
            return 2; // Niepoprawna rama mapy
        // Sprawdzenie, czy długość każdego wiersza jest taka sama jak pierwszego
        if (ft_strlen(map[i]) != firstRowLength)
            return 3; // Niepoprawna rama mapy
        // Sprawdzenie obecności 'M' i 'P' w każdym wierszu
        if (ft_strchr(map[i], 'M') != NULL)
            found_M = 1;
        if (ft_strchr(map[i], 'P') != NULL) 
            found_P = 1;
        i++;
    }

    // Sprawdzenie pierwszej i ostatniej kolumny w każdym wierszu
    i = 0;
    while (i < (firstRowLength - 1))
    {
        if (map[0][i] != '1' || map[e - 1][i] != '1')
            return 5; // Niepoprawna rama mapy
        i++;
    }

    // Jeśli 'M' lub 'P' nie zostały znalezione, zwraca 0, w przeciwnym razie 1
    if (!found_M || !found_P)
        return 5; // 'M' lub 'P' nie zostały znalezione w mapie

    return 1; // Poprawna rama mapy
}


int main() 
{
    int fd;
    char **line;
    int count = 0;
    char *s;

    fd = open("./maps/map2.ber", O_RDONLY);
    if (fd == -1) 
    {
        printf("Error opening file");
        return (1);
    }
    while ((s = get_next_line(fd)) != NULL)
        count++;
    lseek(fd, 0, SEEK_SET);
    line = (char **)malloc(sizeof(char *) * count);
    if (line == NULL) 
    {
        printf("Memory allocation failed");
        return 1;
    }
    count = 0; 
    while ((s = get_next_line(fd)) != NULL) 
    {
        line[count] = s;
       // printf("[%d]: %s", count, line[count]);
        count++;
    }
    close(fd);
    if(ft_maps_errors(line, count) != 1)
        return (printf("wrong"), 0);
    ft_pre_dfs(line, count);
    for (int i = 0; i < count; i++) 
        free(line[i]);
    free(line);

    return 0;
}
