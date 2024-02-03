/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:06:36 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:34:18 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
/*sprawdzic działanie w tej fajne

Funkcja memmove() kopiuje blok pamięci o określonej
 długości z jednej lokalizacji w pamięci do innej 
 lokalizacji w pamięci.
Podobnie jak funkcja memcpy(), ale z jednym ważnym 
dodatkowym aspektem: memmove() jest w stanie obsłużyć sytuacje, 
gdy obszary źródłowy i docelowy się nakładają.
 W takim przypadku memmove() zapewnia, że dane 
 są poprawnie skopiowane, niezależnie od tego,
czy źródło jest skopiowane przed docelową lokalizacją, czy za nią. 
Funkcja ta jest zazwyczaj wolniejsza niż 
memcpy(), ale bardziej wszechstronna*/
