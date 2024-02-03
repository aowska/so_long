/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_procent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:06:47 by awacowsk          #+#    #+#             */
/*   Updated: 2023/08/02 20:06:49 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_char_procent(int c, char **str)
{
	{
		*str = (char *)malloc((2) * sizeof(char));
		if (!*str)
			return ;
		(*str)[0] = c;
		(*str)[1] = '\0';
	}
	return ;
}
