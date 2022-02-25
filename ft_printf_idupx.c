/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_idupx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:25:49 by youskim           #+#    #+#             */
/*   Updated: 2022/02/24 14:26:10 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	*u_to_str(unsigned int n)
{
	char			*ret;
	unsigned int	temp;
	int				len;

	temp = n;
	len = 1;
	while (temp >= 10)
	{
		temp = temp / 10;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (NULL);
	ret[len] = '\0';
	while (len > 0)
	{
		ret[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}

static int	print_id(int n)
{
	char	*ch_itoa;
	int		len;

	ch_itoa = ft_itoa(n);
	len = ft_strlen(ch_itoa);
	write(1, ch_itoa, len);
	free(ch_itoa);
	return (len);
}

static int	print_u(unsigned int n)
{
	char	*u_to_s;
	int		len;

	u_to_s = u_to_str(n);
	len = ft_strlen(u_to_s);
	write(1, u_to_s, len);
	free (u_to_s);
	return (len);
}

static int	print_x(char type, unsigned long long n)
{
	char	*n_to_hex;
	int		len;
	int		i;

	n_to_hex = change_hex(n);
	len = ft_strlen(n_to_hex);
	i = 0;
	if (type == 'X')
	{
		while (n_to_hex[i] != '\0')
		{
			if (n_to_hex[i] >= 'a' && n_to_hex[i] <= 'z')
				n_to_hex[i] -= 32;
			i++;
		}
	}
	write(1, n_to_hex, len);
	free(n_to_hex);
	return (len);
}

int	print_idupx(char type, va_list ap)
{
	if (type == 'i' || type == 'd')
		return (print_id(va_arg(ap, int)));
	else if (type == 'p')
	{
		write (1, "0x", 2);
		return (2 + print_x('x', va_arg(ap, unsigned long long)));
	}
	else if (type == 'u')
		return (print_u(va_arg(ap, unsigned int)));
	else
		return (print_x(type, va_arg(ap, unsigned int)));
}
