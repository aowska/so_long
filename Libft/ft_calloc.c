/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:53:06 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 19:54:53 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*n;

	n = malloc(number * size);
	if (n != NULL)
		ft_memset(n, 0, number * size);
	return (n);
}
/* number - liczba argumentow
size rozmiar kazdego armunemtu */
