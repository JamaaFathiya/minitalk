/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:36:25 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/17 21:17:35 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_pointer(unsigned long int n);
int	ft_putuns(unsigned int n);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned int n, char c);
int	ft_strlen(char *str);
int	ft_printf(const char *format, ...);
int	ft_atoi(const char *nptr);

#endif
