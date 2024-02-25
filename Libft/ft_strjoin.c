/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:45:36 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:45:58 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	ptr = NULL;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	else if (s1 != NULL && s2 == NULL)
		return (ft_strcpy(ptr, s1));
	else if (s1 == NULL && s2 != NULL)
		return (ft_strcpy(ptr, s2));
	else if (s1 && s2)
		return (ft_strcat(ft_strcpy(ptr, s1), s2));
	else
		return (free(ptr), NULL);
}

/*#include <unistd.h>
#include <stdio.h>
int main (int ac, char *av[])
{
	av[1] = "ALA\0";
	av[2] = "\n\0";
	printf("%salala",ft_strjoin(av[1], av[2]));
	return (0);
}*/
