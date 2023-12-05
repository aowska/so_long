/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:37:23 by awacowsk          #+#    #+#             */
/*   Updated: 2023/05/14 19:37:30 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr_fd(char *s, size_t *b, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	*b += ft_strlen(s);
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
