/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:20:37 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 18:15:06 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags 	ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	ft_approve_flags(char c)
{
	if (!ft_is_type(c) && !ft_isdigit(c) && !ft_is_flag(c))
		return (1);
	return (0);
}	

int	ft_parse_flags(const char *format, int i, t_flags *flags, va_list args)
{
	while (format[i])
	{
		if (ft_approve_flags(format[i]))
			break ;
		if (format[i] == '0' && !(flags->minus) && !(flags->width))
			flags->zero = 1;
		if (format[i] == '.')
			i = ft_flag_dot(format, i, flags, args);
		if (format[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (format[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(format[i]))
		{
			if (flags->star == 1)
				flags->width = 0;
			flags->width = (flags->width * 10) + (format[i] - '0');
		}
		if (ft_is_type(format[i++]))
		{
			flags->type = format[--i];
			break ;
		}
	}
	return (i);
}

int	ft_start(const char *format, va_list args)
{
	int			i;
	int			count;
	t_flags		flags;

	i = 0;
	count = 0;
	while (format[i])
	{
		flags = ft_init_flags();
		if (format[i] == '%' && format[i + 1])
		{
			i = ft_parse_flags(format, ++i, &flags, args);
			if (ft_is_type(format[i]))
				count += ft_putconversion((char)flags.type, flags, args);
			else
				return (count);
		}
		else if (format[i] != '%')
			count += ft_putchar_retint(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count += ft_start(format, args);
	va_end(args);
	return (count);
}
