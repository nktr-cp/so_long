/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:28:56 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/18 18:28:50 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_count(long value, int base_size)
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

char	*ft_itoa_decimal(int value)
{
	long	lnb;
	int		is_negative;
	int		digit;
	char	*result;

	lnb = value;
	is_negative = value < 0;
	digit = digit_count(value, 10);
	result = (char *)malloc(digit + is_negative + 1);
	if (result == NULL)
		return (NULL);
	result[digit + is_negative] = '\0';
	if (is_negative)
	{
		result[0] = '-';
		lnb *= -1;
	}
	while (digit--)
	{
		result[is_negative + digit] = '0' + lnb % 10;
		lnb /= 10;
	}
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ret;

	ret = ft_strlen(src);
	if (size == 0)
		return (ret);
	while (--size && *src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
