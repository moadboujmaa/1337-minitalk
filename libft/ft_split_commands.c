/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:46:19 by mboujama          #+#    #+#             */
/*   Updated: 2024/03/17 09:36:45 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_quote(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*str && str[len] != '\'')
	{
		if (str[len] == '\'')
			break ;
		len++;
	}
	return (ft_substr(str, 0, len));
}

char	*get_next_space(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*str && str[len] != ' ')
	{
		if (str[len] == ' ')
			break ;
		len++;
	}
	return (ft_substr(str, 0, len));
}

t_list	*ft_split_commands(char const *str)
{
	t_list	*node;

	node = NULL;
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
		{
			if (*str == '\'')
			{
				ft_lstadd_back(&node, ft_lstnew(get_next_quote((char *)++str)));
				str += ft_strlen(get_next_quote((char *)str)) + 1;
			}
			else
			{
				ft_lstadd_back(&node, ft_lstnew(get_next_space((char *)str)));
				str += ft_strlen(get_next_space((char *)str));
			}
			if (*str)
				str++;
		}
	}
	return (node);
}
