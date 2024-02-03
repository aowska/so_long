/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:53:00 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 20:27:59 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_atoi(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	nb;
	int	v;

	i = 0;
	n = 1;
	nb = 0;
	v = 0;
	i = check_atoi(str, i);
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i + 1] == 45 || str[i + 1] == 43)
			return (0);
		if (str[i++] != 43)
			n = n * (-1);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = str[i++] - '0';
		v = v * 10 + nb;
	}
	v = v * n;
	return (v);
}
