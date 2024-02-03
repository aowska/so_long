/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:39:58 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/30 22:40:33 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_word(int c, char **str)
{
	*str = (char *)malloc((2) * sizeof(char));
	if (!*str)
		return ;
	else
	{
		(*str)[0] = c;
		(*str)[1] = '\0';
	}
	return ;
}
