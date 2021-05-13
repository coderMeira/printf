/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:59:07 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 18:25:38 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_retint(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_convert_char(int c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
		count += ft_putchar_retint(c);
	count += ft_putwidth(flags.width, 1, flags.zero);
	if (!flags.minus)
		count += ft_putchar_retint(c);
	return (count);
}
