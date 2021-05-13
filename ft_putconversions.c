/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putconversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:41:31 by fmeira            #+#    #+#             */
/*   Updated: 2021/04/30 17:15:03 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putconversion(char type, t_flags flags, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_convert_char(va_arg(args, int), flags);
	else if (type == 's')
		count = ft_convert_string(va_arg(args, char *), flags);
	else if (type == 'd' || type == 'i')
		count = ft_convert_int(va_arg(args, int), flags);
	else if (type == 'x' || type == 'X' || type == 'u')
		count = ft_convert_u_x(type, va_arg(args, unsigned int), flags);
	else if (type == 'p')
		count = ft_convert_p(va_arg(args, unsigned long long), flags);
	else if (type == '%')
		count = ft_convert_char('%', flags);
	return (count);
}

int	ft_putwidth(int width, int slots, int zero)
{
	int	count;
	int	diff;

	count = 0;
	diff = width - slots;
	while (diff > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		diff--;
		count++;
	}
	return (count);
}
