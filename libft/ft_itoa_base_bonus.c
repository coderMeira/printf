/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:46:04 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/01 21:22:05 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_check(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	get_l(unsigned long n, int b)
{
	int	l;

	if (n == 0)
		return (1);
	l = 0;
	while (n > 0)
	{
		n /= b;
		l++;
	}
	return (l);
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	int		b;
	int		len;
	char	*nbr;

	b = base_check(base);
	if (!b)
		return (NULL);
	len = get_l(n, b);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (n == 0)
		nbr[0] = base[0];
	while (len > 0)
	{
		nbr[--len] = base[n % b];
		n /= b;
	}
	return (nbr);
}

char	*ft_itoa_long_base(unsigned long long n, char *base)
{
	unsigned long long		b;
	unsigned long long		len;
	char					*nbr;

	b = base_check(base);
	if (!b)
		return (NULL);
	len = get_l(n, b);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (n == 0)
		nbr[0] = base[0];
	while (len > 0)
	{
		nbr[--len] = base[n % b];
		n /= b;
	}
	return (nbr);
}
