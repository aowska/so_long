/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:44:33 by awacowsk          #+#    #+#             */
/*   Updated: 2023/03/26 12:44:37 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char const *src)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[a] != '\0')
	{
		dest[i] = src[a];
		a++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
char *ft_strcat(char *dest, char *src);
int main(void)
{
        char dest[50] = "Hello, ";
        char *src = "world!";
        ft_strcat(dest, src);
        printf("The result of concatenating 
        '%s'and '%s' is: %s\n", "Hello, ", "world!", dest);
        return 0;
}*/
