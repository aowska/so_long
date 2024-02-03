/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:55:29 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:55:35 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	size_t	j;
	char	*ptr;

	l = ft_strlen(s);
	i = 0;
	if (len > 0 && l > start)
	{
		if (l - start + 1 < len)
			ptr = (char *)malloc ((j = (l - start + 1)) * sizeof(char));
		else
			ptr = (char *)malloc ((j = (len + 1)) * sizeof(char));
		if (!ptr || !s)
			return (NULL);
		while (i < j - 1)
			ptr[i++] = s[start++];
	}
	else
		ptr = (char *)malloc ((1) * sizeof(char));
	ptr[i] = '\0';
	return (ptr);
}
