/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:41:44 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/27 10:30:44 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr_uns;

	if (nb < 0)
	{
		nbr_uns = (unsigned int)(-1 * nb);
		ft_putchar('-');
	}
	else
		nbr_uns = (unsigned int)nb;
	if (nbr_uns >= 10)
	{
		ft_putnbr(nbr_uns / 10);
		ft_putnbr(nbr_uns % 10);
	}
	else
		ft_putchar(nbr_uns + '0');
	return (count(nb));
}
