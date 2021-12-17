/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:33:49 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/17 21:49:39 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_len;

void	send(char c, int pid)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		pause();
		usleep(100);
	}
}

void	resp(int sig)
{
	static int	count;

	count++;
	if (count == (g_len) * 8 && sig == SIGUSR1)
	{
		ft_printf("[:)] %d Signals sent succefully\n", count);
		ft_printf("[:)] %d Characters sent succefully\n", g_len);
		ft_printf("[:(] SHRIF SALINA. BYE!\n");
	}
}

int	main(int ac, char **av)
{
	int	s_pid;
	int	i;

	if (ac != 3)
		return (1);
	i = 0;
	g_len = ft_strlen(av[2]);
	s_pid = ft_atoi(av[1]);
	signal(SIGUSR1, resp);
	while (av[2][i])
		send(av[2][i++], s_pid);
	send('\n', s_pid);
	return (0);
}
