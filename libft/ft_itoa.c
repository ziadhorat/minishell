/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:29:17 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/11 09:25:30 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** n_len gets the length of the number as chars, e.g. 10 would be 2 and 234 = 3
*/

static int	n_len(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/*
** ft_itoa fills the string char by char by modding the number by ten to get
** the last number and then divs it by 10 to move it up one digit
*/

char		*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	neg = (n < 0 ? 1 : 0);
	len = n_len(n);
	str = ft_strnew((size_t)(len + neg));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	else if (n > 0)
		len--;
	else
		str[0] = '0';
	while (n)
	{
		str[len] = (n < 0) ? '0' + -(n % 10) : '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}
