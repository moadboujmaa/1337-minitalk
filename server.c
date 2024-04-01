/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:16:57 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/01 12:03:21 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler_sig()
{
	printf("hint\n");
}

int	main(void)
{
	int id = fork();
	
	if (id == -1)
		return (1);

	if (id == 0)
	{
		sleep(2);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handler_sig;
		sigaction(SIGUSR1, &sa, NULL);

		int x;
		printf("what is 5 * 3: ");
		scanf("%d", &x);
		if (x == 15)
			printf("Right!");
		else
			printf("nope!");
	}
	return (0);
}
