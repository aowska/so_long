/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:52:30 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 20:01:53 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(src);
	ptr = NULL;
	if (!src)
		return (NULL);
	ptr = (char *)malloc ((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (src[j])
	{
		ptr[j] = src[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
