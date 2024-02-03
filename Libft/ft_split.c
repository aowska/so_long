/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:37:43 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 20:09:14 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_ile(char const *s, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

int	ft_ileword(char const *s, int a, int i, char c)
{
	while (s[i] == c || s[i] == '\0')
	{
		i++;
		a++;
	}
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i - a + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		b;
	int		a;
	int		d;

	i = 0;
	b = 0;
	a = 0;
	d = 0;
	array = (char **)malloc((ft_ile(s, c) + 1) * sizeof(char *));
	if (!s || !array)
		return (0);
	while (array[a])
	{
		array[a] = (char *)malloc((ft_ileword(s, b, i, c)) * sizeof(char));
		while (b < i)
			array[a][d++] = s[b++];
		array[a][i] = '\0';
		a++;
		i = b;
		d = 0;
	}
	array[a] = NULL;
	return (array);
}
