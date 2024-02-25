/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:07:24 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:40:03 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	if (!str)
		return ((char *) NULL);
	while ((*str != '\0') && (*str != c))
		str++;
	if (*str == c)
		return ((char *)str);
	return ((char *) NULL);
}
