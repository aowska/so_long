/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:28:51 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/01 18:10:45 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_to_pointer_hex(size_t i, unsigned long int n1, char **str)
{
	if (n1 == 0)
	{
		*str = ft_strdup("(nil)");
		if (!*str)
			return ;
		return ;
	}
	*str = (char *)malloc((i + 1) * sizeof(char));
	if (!*str)
		return ;
	(*str)[i] = '\0';
	while (i-- >= 2)
	{
		if (n1 % 16 < 10)
			(*str)[i] = (n1 % 16 + '0');
		else
			(*str)[i] = ((n1 % 16) - 10 + 'a');
		n1 = n1 / 16;
	}
	(*str)[1] = 'x';
	(*str)[0] = '0';
	return ;
}

void	ft_pointer_hex(unsigned long int n, char **str)
{
	unsigned long int	n1;
	size_t				i;

	i = 0;
	n1 = n;
	if (n == 0)
	{
		*str = ft_strdup("(nil)");
		if (!*str)
			return ;
		return ;
	}
	while (n1 != 0)
	{
		n1 = n1 / 16;
		i++;
	}
	i = i + 2;
	n1 = n;
	ft_to_pointer_hex(i, n1, str);
}
