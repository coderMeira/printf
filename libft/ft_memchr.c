/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:00:50 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/03 18:42:49 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	cc;
	int				i;

	i = 0;
	cc = c + 0;
	src = (unsigned char *)s;
	while (n--)
	{
		if (src[i] == cc)
			return (src + i);
		i++;
	}
	return (NULL);
}
