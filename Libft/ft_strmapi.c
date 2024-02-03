/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:49:27 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 19:53:03 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*des;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	des = (char *)malloc(ft_strlen(s) + 1);
	if (!des)
		return (0);
	while (s[i])
	{
		des[i] = (*f)(i, s[i]);
		i++;
	}
	des[i] = '\0';
	return (des);
}
