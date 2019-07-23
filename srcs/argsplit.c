/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:44:25 by mbotes            #+#    #+#             */
/*   Updated: 2019/07/23 13:54:54 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	**argsplit(char *str)
{
	char	**arr;
	int		loop;

	loop = 0;
	while (str[loop])
	{
		if (str[loop] == '"')
		{
			loop++;
			while (str[loop] != '"')
				loop++;
		}
		else if (ft_iswhitespace(str[loop]))
			str[loop] = '"';
		loop++;
	}
	arr = ft_strsplit(str, '"');
	ft_strdel(&str);
	return (arr);
}
