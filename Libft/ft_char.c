/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:51:52 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/30 18:51:54 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_char(int c, char **str)
{
	ft_putchar_fd(c, 1);
	*str = (char *)malloc((1) * sizeof(char));
	if (!*str)
		return ;
	else
		(*str)[0] = '\0';
	return ;
}
