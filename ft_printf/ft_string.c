/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:52:15 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/30 18:52:16 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *src, char **ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src)
	{
		*ptr = ft_strdup("(null)");
		if (!*ptr)
			return ;
	}
	else
	{
		i = ft_strlen(src);
		*ptr = (char *)malloc ((i + 1) * sizeof(char));
		if (!*ptr)
			return ;
		while (src[j])
		{
			(*ptr)[j] = src[j];
			j++;
		}
		(*ptr)[j] = '\0';
		return ;
	}
}
