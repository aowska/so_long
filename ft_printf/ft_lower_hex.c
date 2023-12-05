/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:35:04 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/01 19:15:24 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_lower_hex(size_t i, unsigned int n1, char **str)
{
	if (n1 == 0)
	{
		*str = ft_strdup("0");
		return ;
	}
	*str = (char *)malloc((i + 1) * sizeof(char));
	if (!*str)
		return ;
	(*str)[i] = '\0';
	while (i--)
	{
		if (n1 % 16 < 10)
			(*str)[i] = (n1 % 16 + '0');
		else
			(*str)[i] = ((n1 % 16) - 10 + 'a');
		n1 = n1 / 16;
	}
	return ;
}

void	ft_lower_hex(unsigned int n, char **str)
{
	unsigned int	n1;
	size_t			i;

	i = 0;
	n1 = n;
	while (n1 != 0)
	{
		n1 = n1 / 16;
		i++;
	}
	n1 = n;
	ft_to_lower_hex(i, n1, str);
	return ;
}
