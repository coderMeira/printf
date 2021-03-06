/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:23:01 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 21:05:09 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*k;
	int				i;

	p = (unsigned char *)s1;
	k = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (n-- && p && k)
	{
		if (p[i] != k[i])
			return (p[i] - k[i]);
		i++;
	}
	return (0);
}
