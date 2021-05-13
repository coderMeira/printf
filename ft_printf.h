/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:49:16 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/02 17:24:19 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int			ft_printf(const char *format, ...);
int			ft_start(const char *format, va_list args);
int			ft_parse_flags(const char *format, int i, t_flags *flags,
				va_list args);
t_flags		ft_init_flags(void);
int			ft_is_flag(char c);
int			ft_flag_dot(const char *format, int i, t_flags *flags,
				va_list args);
t_flags		ft_flag_minus(t_flags flags);
t_flags		ft_flag_width(va_list args, t_flags flags);
int			ft_is_type(char c);
int			ft_putchar_retint(char c);
int			ft_putconversion(char type, t_flags flags, va_list args);
int			ft_convert_char(int c, t_flags flags);
int			ft_convert_string(char *s, t_flags flags);
int			ft_convert_p(unsigned long long p, t_flags flags);
int			ft_convert_int(int i, t_flags flags);
int			ft_convert_u_x(char type, unsigned int h, t_flags flags);
int			ft_convert_percent(t_flags flags);
int			ft_putwidth(int width, int slots, int zero);
int			ft_putstr_len(char *str, size_t len);
int			ft_putint_len(char *str, t_flags flags);
int			ft_handle_ints(char *str, t_flags *flags, int len);
int			ft_length(char *str, t_flags flags, int i);

#endif
