/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:44:15 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/27 10:32:28 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countb(unsigned int nb)
{
	int	i;

	i = 0;
	if (!nb)
		i++;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

int	ft_putnbr_base(unsigned int nb, char x)
{
	char	*l;
	char	*u;

	u = "0123456789ABCDEF";
	l = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbr_base((nb / 16), x);
		ft_putnbr_base((nb % 16), x);
	}
	else
	{
		if (x == 'x')
			write(1, &l[nb], 1);
		else
			write(1, &u[nb], 1);
	}
	return (countb(nb));
}
