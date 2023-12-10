/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42berlin.de      +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:32:40 by awacowsk          #+#    #+#             */
/*   Updated: 2023/07/30 23:32:42 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	get_value(const char *word, va_list *pw, char **v)
{
	if (*word == 'c' )
		ft_char(va_arg(*pw, int), v);
	else if (*word == 's')
		ft_string(va_arg(*pw, char *), v);
	else if (*word == 'X')
		ft_upper_hex(va_arg(*pw, unsigned int), v);
	else if (*word == 'i' || *word == 'd' )
		ft_itoa_dec(va_arg(*pw, int), v);
	else if (*word == 'x')
		ft_lower_hex(va_arg(*pw, unsigned int), v);
	else if (*word == 'p')
		ft_pointer_hex(va_arg(*pw, unsigned long long), v);
	else if (*word == '%')
		ft_char_procent('%', v);
	else if (*word == 'u')
		ft_itoa_unsign(va_arg(*pw, unsigned int), v);
}

int	ft_printf(const char *word, ...)
{
	size_t	i;
	char	*value;
	va_list	pw;

	if (!word)
		return (-1);
	va_start(pw, word);
	i = 0;
	value = NULL;
	while (*word)
	{
		if (*word != '%')
			ft_char_word(*word, &value);
		else
		{
			get_value(++word, &pw, &value);
			if (*(word) == 'c')
				i++;
		}
		ft_putstr_fd(value, &i, 1);
		word++;
		free(value);
	}
	return (va_end(pw), (int)i);
}

/*
int	main(void)
{
	char			ch = 'c';
	char			str[] = "Hello, user!";
	char			*ptr;
	int				int1 = -1234565;
	int				int2 = -3934555;
	unsigned int	uns = -2147483648;
	unsigned int	hex_low = -1233454;
	unsigned int	hex_up = -1233454;
	int	result;

	ptr = &ch;
	printf("\n\nStandard PRINTF function:\n");
	result = printf("%c", ch);
	printf("\t\t- character, return value 'c': %d\n", result);
	result = printf("%s", str);
	printf("\t- string, return value 's': %d\n", result);
	result = printf("%d", int1);
	printf("\t- int, decimal, return value 'd': %d\n", result);
	result = printf("%i", int2);
	printf("\t- int, whole number, decimal, return value 'i': %d\n", result);
	result = printf("%u", uns);
	printf("\t- unsigned int, decimal, return value 'u': %d\n", result);
	result = printf("%p", ptr);
	printf("\t- address, return value 'p': %d\n", result);
	result = printf("%x", hex_low);
	printf("\t- unsigned int, hex, lowercase, return value 'x': %d\n", result);
	result = printf("%X", hex_up);
	printf("\t- unsigned int, hex, uppercase, return value 'X': %d\n", result);
	result = printf("%%");
	printf("\t\t- percent sign, return value: %d\n", result);

	printf("\t\tMIX  %c %s %d %i %u %p %X %x %% \n", ch, str,
		int1, int2, uns, ptr, hex_low, hex_up);

	ft_printf("\n\nMy FT_PRINTF function:\n");
	result = ft_printf("%c", ch);
	printf("\t\t- character, return value 'c': %d\n", result);
	result = ft_printf("%s", str);
	printf("\t- string, return value 's': %d\n", result);
	result = ft_printf("%d", int1);
	printf("\t- int, decimal, return value 'd': %d\n", result);
	result = ft_printf("%i", int2);
	printf("\t- int, whole number, decimal, return value 'i': %d\n", result);
	result = ft_printf("%u", uns);
	printf("\t- unsigned int, decimal, return value 'u': %d\n", result);
	result = ft_printf("%p", ptr);
	printf("\t- address, return value 'p': %d\n", result);
	result = ft_printf("%x", hex_low);
	printf("\t- unsigned int, hex, lowercase, return value 'x': %d\n", result);
	result = ft_printf("%X", hex_up);
	printf("\t- unsigned int, hex, uppercase, return value 'X': %d\n", result);
	result = ft_printf("%%");
	printf("\t\t- percent sign, return value: %d\n\n", result);


	ft_printf("\t\tMIX  %c %s %d %i %u %p %X %x %% \n", ch,
		str, int1, int2, uns, ptr, hex_low, hex_up);
	
	
	int len1 = ft_printf(NULL);
	ft_printf("%d\n", len1);
	int len2 = printf(NULL);
	printf("%d\n", len2);
	int len3 = ft_printf("");
	ft_printf("%d\n", len3);
	int len4 = printf("");
	printf("%d\n\n", len4);

	int i = printf("%c", 0);
	int j = ft_printf("%c", 0);
	printf("%d vs %d\n", i, j);
	return (0);
}
*/