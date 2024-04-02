/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:16:38 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/02 09:44:32 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(t_data data)
{
	int				i;
	unsigned char	bit;
	char			*str;

	str = data.text;
	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			bit = (*str >> i & 1) + '0';
			if (bit == '0')
				kill(data.server_id, SIGUSR1);
			else
				kill(data.server_id, SIGUSR2);
			usleep(150000);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 3)
	{
		data.server_id = ft_atoi(argv[1]);
		data.text = argv[2];
		send_bits(data);
	}
	else
		ft_putstr_fd("Executed like this: ./client <pid> <text>", 2);
	return (0);
}
