/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:16:38 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/01 13:16:35 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int server_id = ft_atoi(argv[1]);
		kill(server_id, SIGUSR1);
		kill(server_id, SIGUSR2);
	}
	else
		ft_putstr_fd("Executed like this: ./client <pid> <text>", 2);
	return (0);
}
