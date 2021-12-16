/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:23:14 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/27 10:30:07 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter(unsigned long int n)
{
	int	i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_pointer(unsigned long int n)
{
	char				*b;

	b = "0123456789abcdef";
	if (n >= 16)
	{
		ft_pointer((n / 16));
		ft_pointer((n % 16));
	}
	else
	{
		write(1, &b[n], 1);
	}
	return (counter(n));
}
