/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:33:26 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/11 09:26:10 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)s + i);
	while (i)
	{
		i--;
		if (c == s[i])
			return ((char *)s + i);
	}
	return (NULL);
}
