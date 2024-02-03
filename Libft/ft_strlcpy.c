/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:52:02 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:48:16 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (ft_strlen(s2));
	while (s2[i] != '\0' && i < s - 1)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	while (s2[i] != '\0')
	{
		i++;
	}
	return (i);
}
