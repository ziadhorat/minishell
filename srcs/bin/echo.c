/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:44:30 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 14:20:10 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define IS_QUOTE(c) ((c == '"' || c == '\'') ? 1 : 0)
#include "../../includes/minishell.h"

static void		ft_putsubstr(char *str, int index_offset, int end_offset)
{
	int		i;
	int		len;

	i = index_offset;
	len = ft_strlen(str) + end_offset;
	while (i < len)
		ft_putchar(str[i++]);
}

static void		echo_command(char **str, int index)
{
	int		len;
	int		start_quote;
	int		end_quote;

	while (str[index])
	{
		len = ft_strlen(str[index]);
		start_quote = IS_QUOTE(str[index][0]);
		end_quote = IS_QUOTE(str[index][len - 1]);
		if (start_quote && end_quote)
			ft_putsubstr(str[index], 1, -1);
		else if (start_quote)
			ft_putstr(str[index] + 1);
		else if (end_quote)
			ft_putsubstr(str[index], 0, -1);
		else
			ft_putstr(str[index]);
		ft_putchar((str[index + 1]) ? ' ' : '\0');
		index++;
	}
}

int				echo_b(char **command)
{
	int		i;
	int		n_flag;

	i = 1;
	if (!command[1])
	{
		ft_putchar('\n');
		return (0);
	}
	n_flag = (ft_strequ("-n", command[1]) == 1) ? 1 : 0;
	i += n_flag;
	if (n_flag && !command[2])
	{
		return (0);
	}
	echo_command(command, i);
	if (!n_flag)
		ft_putchar('\n');
	return (0);
}
