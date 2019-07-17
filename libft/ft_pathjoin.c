/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:49:31 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 13:54:06 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pathjoin(char *s1, char *s2)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(s1, "/");
	result = ft_strjoin(temp, s2);
	free(temp);
	return (result);
}
