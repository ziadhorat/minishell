/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:49:42 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 13:54:34 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinchf(char *str, char c)
{
	char	*new;

	new = ft_strjoinch(str, c);
	if (!new)
		return (NULL);
	free(str);
	str = NULL;
	return (new);
}
