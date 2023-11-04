/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:21:35 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 14:34:41 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (new_str)
	{
		i = 0;
		while (*src)
			new_str[i++] = *src++;
		new_str[i] = '\0';
	}
	return (new_str);
}

static unsigned long	unsigned_digit_count(unsigned long value, int base_size)
{
	int	digit;

	digit = 0;
	if (value == 0)
		digit++;
	while (value)
	{
		value /= base_size;
		digit++;
	}
	return (digit);
}

char	*ft_itoa_positive_hex(unsigned long value)
{
	int			digit;
	char		*result;

	digit = unsigned_digit_count(value, 16);
	result = (char *)malloc(digit + 3);
	if (result == NULL)
		return (NULL);
	result[digit + 2] = '\0';
	while (digit--)
	{
		result[digit + 2] = LOWER_HEX[value % 16];
		value /= 16;
	}
	result[0] = '0';
	result[1] = 'x';
	return (result);
}
