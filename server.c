/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:33:30 by fathjami          #+#    #+#             */
/*   Updated: 2021/12/16 17:30:46 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset(char *a, int *b)
{
	*a = 0;
	*b = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits;
	static int	cur_pid;
	int			new_pid;

	(void)context;
	if (!cur_pid)
		cur_pid = info->si_pid;
	new_pid = info->si_pid;
	if (new_pid != cur_pid)
	{
		cur_pid = new_pid;
		reset(&c, &bits);
	}
	c |= (sig == SIGUSR2);
	c <<= 1;
	if (bits == 8)
	{
		ft_printf("%c", c);
		reset(&c, &bits);
	}
	bits++;
	usleep(100);
	kill(cur_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	ft_printf("Use this pid: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
