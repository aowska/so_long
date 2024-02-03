/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:53:18 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 19:59:40 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t						i;
	const unsigned char			*p;
	unsigned char				uc;

	i = 0;
	p = (const unsigned char *)s;
	c = (unsigned char)c;
	uc = c;
	while (i < n)
	{
		if (*p == uc)
		{
			return ((void *)p);
		}
		p++;
		i++;
	}
	return (NULL);
}

/*Funkcja przyjmuje trzy argumenty:
s-wskaźnik na początek bloku pamięci, 
w którym szukamy 
określonej wartości bajtu.
c - wartość bajtu, którą szukamy.
n - maksymalna liczba 
bajtów, które 
mogą zostać przeszukane.
Funkcja zwraca wskaźnik 
na pierwsze 
wystąpienie wartości bajtu c 
w bloku pamięci s,
lub wartość NULL, gdy wartość ta nie 
występuje w bloku pamięci lub gdy 
n jest równe zero.*/
