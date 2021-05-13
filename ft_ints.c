/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:52:07 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 18:38:33 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
int	ft_putint_len(char *str, t_flags flags)
{
	int	count;
	int	len;
	int	l;

	count = 0;
	len = ft_strlen(str);
	l = len;
	if (!str)
		return (0);
	if (*(str) == '-')
	{
		len--;
		count += ft_putchar_retint(*(str++));
	}	
	if (flags.dot > len || (flags.zero && (flags.width > len)))
	{
		while (flags.dot-- > len || (flags.zero && (flags.width > l++)))
			count += ft_putchar_retint('0');
	}
	while (len-- && *str)
		count += ft_putchar_retint(*(str++));
	return (count);
}

int 	ft_length(char *str, t_flags flags, int i)
{
	int	len;

	len = ft_strlen(str);
	if (i < 0)
		len--;
	if (flags.dot > len)
		len = flags.dot;
	if (i < 0)
		len++;
	return (len);
}

int 	ft_handle_ints(char *str, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (flags->dot >= 0 && flags->zero)
	{
		flags->zero = 0;
		count += ft_putwidth(flags->width, len, flags->zero);
	}
	else if (flags->dot < 0 && (flags->zero && (flags->width > len)))
	{
		count += ft_putint_len(str, *flags);
		flags->minus = 1;
	}
	else
		count += ft_putwidth(flags->width, len, flags->zero);
	return (count);
}	

int	ft_convert_int(int i, t_flags flags)
{
	int			count;
	int			len;
	char		*str;
	t_flags		*p;

	count = 0;
	p = &flags;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_putwidth(flags.width, 0, 0);
		return (count);
	}
	str = ft_itoa(i);
	len = ft_length(str, flags, i);
	if (flags.minus)
		count += ft_putint_len(str, flags);
	count += ft_handle_ints(str, p, len);
	if (!flags.minus)
		count += ft_putint_len(str, flags);
	free(str);
	return (count);
}
