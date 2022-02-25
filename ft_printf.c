/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youskim <youskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:19:07 by youskim           #+#    #+#             */
/*   Updated: 2022/02/25 13:42:33 by youskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	print_s(char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

static int	print_type(char type, va_list ap)
{
	int	a;

	if (type == 'c')
	{
		a = va_arg(ap, int);
		write(1, &a, 1);
		return (1);
	}
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (type == 's')
		return (print_s(va_arg(ap, char *)));
	else
		return (print_idupx(type, ap));
}

int	ft_printf(const char *format, ...)
{
	char	type;
	va_list	ap;
	int		i;
	int		re_val;

	i = 0;
	re_val = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			type = format[i + 1];
			re_val += print_type(type, ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			re_val++;
		}
		i++;
	}
	va_end(ap);
	return (re_val);
}
