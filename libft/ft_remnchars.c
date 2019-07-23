/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remnchars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:53:35 by mbotes            #+#    #+#             */
/*   Updated: 2019/07/23 11:01:48 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remnchars(char **c, size_t n)
{
	char	*str;

	str = ft_strdup(*(c) + n);
	ft_strdel(c);
	if (str != NULL)
		*c = ft_strdupdel(&str);
}
