/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:44:29 by fmeira            #+#    #+#             */
/*   Updated: 2021/02/19 15:15:07 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	cc;
	size_t			i;
	void			*ss;

	ss = s;
	cc = c + 0;
	i = 0;
	while (i < n)
	{
		*((unsigned char *)ss) = cc;
		ss++;
		i++;
	}
	return (s);
}
