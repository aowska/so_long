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

char*	ft_strstr(const char* haystack, const char* needle) 
{
	while (*haystack)
	{
		const char* h = haystack;
		const char* n = needle;
		while (*h == *n && *n)
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char*)haystack); 
		haystack++;
	}
	return (NULL);
}
