/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:16:57 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/04 17:16:53 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	sighandler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	check_client(&g_data, info->si_pid);
	if (g_data.receive < 32)
		receive_len(&g_data, sig);
	else
	{
		if (!g_data.is_allocated)
			alloc_text(&g_data, g_data.len);
		if (sig == SIGUSR1)
			g_data.c = g_data.c << 1;
		else if (sig == SIGUSR2)
			g_data.c = (g_data.c << 1) | 1;
		g_data.index++;
		if (g_data.index > 7)
		{
			g_data.text_received[g_data.text_index++] = g_data.c;
			g_data.index = 0;
		}
		if (g_data.text_index == g_data.len)
		{
			ft_printf("%s\n", g_data.text_received);
			kill(g_data.client_id, SIGUSR1);
		}
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
