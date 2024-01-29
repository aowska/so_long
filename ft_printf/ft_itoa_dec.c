/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:48:50 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 19:41:09 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_toa(size_t i, long int n1, long int n, char **str)
{
	if (n == 0)
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
		(*str)[i] = (n1 % 10) + '0';
		n1 = n1 / 10;
	}
	if (n < 0)
		(*str)[0] = '-';
}

void	ft_itoa_dec(long int n, char **str)
{
	long int	n1;
	size_t		i;

	i = 0;
	n1 = n;
	*str = NULL;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		i++;
	}
	n1 = n;
	if (n < 0)
	{
		n1 *= -1;
		i++;
	}
	ft_toa(i, n1, n, str);
	return ;
}
