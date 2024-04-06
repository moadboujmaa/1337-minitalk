/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:13:12 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/06 09:41:02 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	sighandler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message received successfully\n");
		exit(0);
	}
}

void	send_len(int len)
{
	int	i;
	int	bit;

	i = 32;
	while (--i >= 0)
	{
		bit = (len >> i) & 1;
		if (bit == 0)
			kill(g_data.server_id, SIGUSR1);
		else
			kill(g_data.server_id, SIGUSR2);
		usleep(150);
	}
}

void	send_bits(void)
{
	int				i;
	int				bit;
	const char		*str; 

	str = g_data.text;
	send_len(ft_strlen(str));
	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			bit = *str >> i & 1;
			if (bit == 0)
				kill(g_data.server_id, SIGUSR1);
			else
				kill(g_data.server_id, SIGUSR2);
			usleep(150);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		g_data.server_id = ft_atoi(argv[1]);
		g_data.text = argv[2];
		signal(SIGUSR1, sighandler);
		send_bits();
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Executed like this: ./client <pid> <text>", 2);
	return (0);
}
