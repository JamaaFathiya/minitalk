/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:06:26 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/27 10:09:40 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	core(char c, va_list arg, int *counter)
{
	if (c == 'c')
		*counter += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		*counter += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		ft_putstr("0x");
		*counter += 2 + ft_pointer(va_arg(arg, unsigned long int));
	}
	else if (c == 'i' || c == 'd')
		*counter += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		*counter += ft_putuns(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		*counter += ft_putnbr_base(va_arg(arg, int), c);
	else if (c == '%')
		*counter += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start (arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			core(*format, arg, &count);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
