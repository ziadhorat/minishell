/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:49:36 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/17 13:54:18 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_starts_with(char *to_start, char *str)
{
	int		i;

	i = 0;
	while (to_start[i] && str[i] && (to_start[i] == str[i]))
		i++;
	return (to_start[i] == '\0' ? 1 : 0);
}
