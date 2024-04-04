/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:37:52 by mboujama          #+#    #+#             */
/*   Updated: 2024/04/04 17:09:28 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_data {
	char	*text_received;
	int		index;
	char	c;
	int		len;
	int		receive;
	char	*text;
	int		client_id;
	int		is_allocated;
	int		text_index;
	int		server_id;
}	t_data;

void	alloc_text(t_data *g_data, int len);
void	init_g_data(t_data *g_data, pid_t pid);
void	receive_len(t_data *g_data, int sig);
void	check_client(t_data *g_data, pid_t pid);

#endif
