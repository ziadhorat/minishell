/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:58:24 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 13:58:33 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char *s1, char c)
{
	int		i;
	int		len;
	char	*result;

	if (!s1 && !c)
		return (NULL);
	if (!s1)
	{
		result = ft_strnew(1);
		result[0] = c;
	}
	else if (!c)
		return (s1);
	else
	{
		i = -1;
		len = ft_strlen(s1);
		result = ft_strnew(len + 1);
		while (++i < len)
			result[i] = s1[i];
		result[i] = c;
	}
	return (result);
}
