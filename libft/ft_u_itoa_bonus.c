/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:00:42 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 20:54:00 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen_u(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_u_itoa(unsigned int n)
{
	char	*res;
	size_t	len;
	long	nbr;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = n;
	len = numlen_u(nbr);
	res = (char *)malloc(len + 1 * sizeof(char));
	if (!res)
		return (0);
	res[len--] = '\0';
	if (nbr == 0)
		res[0] = '0';
	else if (nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		res[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (res);
}
