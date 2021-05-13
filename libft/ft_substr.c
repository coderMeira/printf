/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:21:25 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/03 20:02:02 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = '\0';
		return (p);
	}
	if (s_len < len)
		return (ft_strdup((char *)s + start));
	i = 0;
	p = (char *)malloc(len + 1 * sizeof(char));
	if (!p)
		return (0);
	while (start < s_len && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
