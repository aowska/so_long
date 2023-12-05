/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:09:32 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/24 20:09:34 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char s, int fd);
void	ft_itoa_dec(long int n, char **str);
void	ft_lower_hex(unsigned int n, char **str);
void	ft_pointer_hex(unsigned long int n, char **str);
void	ft_upper_hex(unsigned int n, char **str);
void	ft_itoa_unsign(unsigned int n, char **str);
void	ft_char(int a, char **str);
void	ft_char_word(int a, char **str);
void	ft_string(char *src, char **ptr);
void	ft_putstr_fd(char *s, size_t *b, int fd);
char	*ft_strdup(char *src);
void	ft_char_procent(int c, char **str);
int		ft_printf(const char *word, ...);

#endif
