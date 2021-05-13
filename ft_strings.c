/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:45:29 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 18:39:03 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <string.h>

int 	ft_putstr_len(char *str, size_t len)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (len-- && *str)
		count += ft_putchar_retint(*(str++));
	return (count);
}

int 	ft_convert_string(char *s, t_flags flags)
{
	int		count;
	int		len;
	char	*nil;

	count = 0;
	nil = ft_strdup("(null)");
	if (!s)
		s = nil;
	len = ft_strlen(s);
	if (flags.dot >= 0 && flags.dot < len)
		len = flags.dot;
	if (flags.minus)
		count += ft_putstr_len(s, len);
	count += ft_putwidth(flags.width, len, flags.zero);
	if (!flags.minus)
		count += ft_putstr_len(s, len);
	free(nil);
	return (count);
}
