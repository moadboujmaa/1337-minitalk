/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:16:57 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/01 13:21:32 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sighandler(int sig)
{
	if (sig == SIGUSR1)
		printf("Hello!\n");
	else if (sig == SIGUSR2)
		printf("World\n");
}

int	main(void)
{
	int pid = getpid();
	struct sigaction sa;

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", pid);
	while (1);
	return (0);
}
