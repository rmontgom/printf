/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:18:18 by rmontgom          #+#    #+#             */
/*   Updated: 2021/12/02 17:31:32 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf_di(long long n);
int	ft_printf_u(unsigned int n);
int	ft_parser(char c, va_list ap);
int	ft_printf(const char *str, ...);
int	ft_putpointer(unsigned long n);
int	ft_put_lhex(unsigned int n);
int	ft_put_hhex(unsigned int n);

#endif