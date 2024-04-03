/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:16:57 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/03 14:36:37 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	sighandler(int sig, siginfo_t *info, void *context)
{
	static int		c;

	(void) context;
	if (!g_data.client_id)
		g_data.client_id = info->si_pid;
	if (g_data.client_id != info->si_pid)
	{
		g_data.client_id = info->si_pid;
		g_data.index = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	g_data.index++;
	if (c == '\0')
		printf("\n");
	if (g_data.index > 7)
	{
		write(1, &c, 1);
		g_data.index = 0; 
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	g_data.index = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}
