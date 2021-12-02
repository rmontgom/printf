/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:25:11 by rmontgom          #+#    #+#             */
/*   Updated: 2021/12/02 17:31:28 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_di(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		len += ft_printf_di(n * -1);
	}
	else if (n >= 10 && n < 2147483648)
	{
		len += ft_printf_di(n / 10);
		len += ft_printf_di(n % 10);
	}
	else if (n == 2147483648)
	{
		len += write(1, "2147483648", 10);
	}
	else
	{
		len += ft_putchar(n + '0');
	}
	return (len);
}

int	ft_printf_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_printf_di(n / 10);
		len += ft_printf_di(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_putpointer(unsigned long n)
{
	int		i;
	int		len;
	char	*hex;
	char	tmp[17];

	hex = "0123456789abcdef";
	i = 0;
	if (!n)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (n)
	{
		tmp[i++] = hex[n % 16];
		n /= 16;
	}
	tmp[i] = '\0';
	len = i + 2;
	write (1, "0x", 2);
	i--;
	while (i >= 0)
		write (1, &tmp[i--], 1);
	return (len);
}

int	ft_put_lhex(unsigned int n)
{
	int		i;
	int		len;
	char	*hex;
	char	tmp[9];

	hex = "0123456789abcdef";
	i = 0;
	if (!n)
	{
		write (1, "0", 1);
		return (1);
	}
	while (n)
	{
		tmp[i++] = hex[n % 16];
		n /= 16;
	}
	tmp[i] = '\0';
	len = i;
	i--;
	while (i >= 0)
		write (1, &tmp[i--], 1);
	return (len);
}

int	ft_put_hhex(unsigned int n)
{
	int		i;
	int		len;
	char	*hex;
	char	tmp[9];

	hex = "0123456789ABCDEF";
	i = 0;
	len = 0;
	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n)
	{
		tmp[i++] = hex[n % 16];
		n /= 16;
	}
	tmp[i] = '\0';
	len = i;
	i--;
	while (i >= 0)
		write (1, &tmp[i--], 1);
	return (len);
}
