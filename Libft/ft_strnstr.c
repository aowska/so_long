/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:51:11 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:54:41 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	a;
	size_t	i;

	i = 0;
	a = 0;
	if (to_find[a] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		while (str[i + a] != '\0' && str[i + a] == to_find[a] && i + a < len)
		{
			if (to_find[a + 1] == '\0')
				return (&str[i]);
			a++;
		}
		a = 0;
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Hallo Wellt";
	char to_find[] = "We";
	printf("Test: %s|\n", ft_strstr(str, to_find));
	printf("Real: %s|", strstr(str, to_find));
	return (0);
}*/
