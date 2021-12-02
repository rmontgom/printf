/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:38:40 by rmontgom          #+#    #+#             */
/*   Updated: 2021/12/02 17:31:35 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	len;
	int	i;

	va_list(ap);
	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += ft_parser(str[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

int	ft_parser(char c, va_list ap)
{
	if (c == 'd' || c == 'i')
		return (ft_printf_di(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(ap, int)));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(ap, unsigned long)));
	else if (c == 'x')
		return (ft_put_lhex(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_put_hhex(va_arg(ap, unsigned int)));
	else
		return (ft_putchar('%'));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	str = "(null)";
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
