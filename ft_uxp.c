/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:02:28 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 18:36:45 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_stringify(char letter, unsigned int u)
{
	char			*str;

	if (letter == 'x')
		str = ft_itoa_base(u, "0123456789abcdef");
	else if (letter == 'X')
		str = ft_itoa_base(u, "0123456789ABCDEF");
	else
		str = ft_u_itoa(u);
	return (str);
}

int	ft_convert_u_x(char letter, unsigned int i, t_flags flags)
{
	int				count;
	char			*str;
	t_flags			*p;
	unsigned int	u;
	int				len;

	u = (unsigned int)(4294967295 + 1 + i);
	count = 0;
	p = &flags;
	str = ft_stringify(letter, u);
	len = ft_length(str, flags, 1);
	if (flags.dot == 0 && u == 0)
	{
		count += ft_putwidth(flags.width, 0, 0);
		free(str);
		return (count);
	}
	if (flags.minus)
		count += ft_putint_len(str, flags);
	count += ft_handle_ints(str, p, len);
	if (!flags.minus)
		count += ft_putint_len(str, flags);
	free(str);
	return (count);
}

int	ft_putp_len(char *str, t_flags flags)
{
	int	count;
	int	len;
	int	l;

	count = 0;
	len = ft_strlen(str);
	l = len;
	if (!str)
		return (0);
	if (flags.dot > len - 2)
	{
		ft_putchar_retint(*(str++));
		ft_putchar_retint(*(str++));
		flags.dot += 2;
		count += 2;
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

char	*ft_ppp(unsigned long long i)
{
	char	*str;
	char	*aux;

	aux = ft_itoa_long_base(i, "0123456789abcdef");
	str = ft_strjoin("0x", aux);
	free(aux);
	return (str);
}

int	ft_convert_p(unsigned long long i, t_flags flags)
{
	int		count;
	char	*str;
	t_flags	*p;
	int		len;

	str = ft_ppp(i);
	count = 0;
	p = &flags;
	len = ft_length(str, flags, i);
	if (flags.dot == 0 && i == 0)
	{
		 count += ft_putwidth(flags.width, 2, 0);
		 count += ft_putstr_len("0x", 2);
		 free(str);
		 return (count);
	}
	if (flags.minus)
		count += ft_putp_len(str, flags);
	count += ft_handle_ints(str, p, len);
	if (!flags.minus)
		count += ft_putp_len(str, flags);
	free(str);
	return (count);
}
