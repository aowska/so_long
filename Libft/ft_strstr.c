/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:28:38 by awacowsk          #+#    #+#             */
/*   Updated: 2024/02/04 14:32:20 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	h = NULL;
	n = NULL;
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h == *n && *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
