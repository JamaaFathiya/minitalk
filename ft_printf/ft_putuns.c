/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:14:44 by fathjami          #+#    #+#             */
/*   Updated: 2021/11/27 10:33:38 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countu(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putuns(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putuns(nb / 10);
		ft_putuns(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (countu(nb));
}
