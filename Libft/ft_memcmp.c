/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:53:25 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/03 20:00:25 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*r;
	size_t				i;

	p = (const unsigned char *)s1;
	r = (const unsigned char *)s2;
	i = 0; 
	while (i < n)
	{
		if (*p != *r)
			return (*p - *r);
		p++;
		r++;
		i++;
	}
	return (0);
}

/*Funkcja memcmp() jest funkcją w języku C,
 która służy do porównywania bloków pamięci.
Funkcja ta przyjmuje dwa wskaźniki na bloki 
pamięci do porównania oraz liczbę bajtów do porównania.
Porównanie bloków jest wykonywane bajt po bajcie, 
a funkcja zwraca wartość 0, jeśli bloki są równe, 
wartość mniejszą od 0,
jeśli pierwszy różni się od drugiego na mniejszej
 pozycji lub wartość większą od 0, jeśli drugi różni
  się od pierwszego na mniejszej pozycji.*/
