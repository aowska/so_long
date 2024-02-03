/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:06:05 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:31:13 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*Funkcja kopiuje n bajtów z obszaru źródłowego src do 
obszaru docelowego dest,
a następnie zwraca wskaźnik na obszar docelowy. Zarówno dest, 
jak i src muszą być wskaźnikami na bloki pamięci o 
rozmiarze co najmniej n.
Funkcja ta jest przydatna, gdy chcemy skopiować blok 
pamięci np. w celu przeniesienia danych z jednej zmiennej 
do drugiej,
lub gdy chcemy utworzyć kopię danego fragmentu pamięci, 
aby móc go modyfikować bez wpływu na oryginalne dane.*/
