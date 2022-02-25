/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:36:02 by youskim           #+#    #+#             */
/*   Updated: 2022/02/24 15:05:15 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*str;
	size_t			i;

	a = (unsigned char)c;
	str = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		str[i] = a;
		i++;
	}
	return (str);
}

static int	length_hex(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		length++;
	}
	return (length);
}

char	*change_hex(unsigned int num)
{
	char			*hex;
	char			*i_to_h;
	int				i;

	hex = "0123456789abcdef";
	i_to_h = (char *)malloc(sizeof(char) * (length_hex(num) + 1));
	if (i_to_h == 0)
		return (NULL);
	ft_memset(i_to_h, 0, 9);
	if (num == 0)
	{
		i_to_h[0] = '0';
		return (i_to_h);
	}
	i = length_hex(num);
	while (num > 0)
	{
		i_to_h[i - 1] = hex[num % 16];
		i--;
		num = num / 16;
	}
	return (i_to_h);
}
