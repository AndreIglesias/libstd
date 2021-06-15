/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:21:29 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 16:51:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	%[flag/s][min field width][precision][length modifier]<conversion specifier>
**
**	conversions
**	csp
**	diouxX 	avec les flags hh h l ll
**	f		avec les flags l L
**	%%
**
**	#0-+ espace
**	minimum du champ
**	precision
*/

int			is_conversion(const char c)
{
	return (ft_countchr("diouxXcspf%", c) > 0);
}

int			is_modifier(const char *format, int i)
{
	if (ft_countchr("hlL", format[i]) > 0)
	{
		i++;
		if (format[i] == 'h' || format[i] == 'l')
			i++;
	}
	return (i);
}

int			is_flag(const char c)
{
	return (ft_countchr("#0-+ ", c) > 0);
}

t_flags		init_flags(int i, int fd)
{
	t_flags flags;

	flags.square = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.hh = 0;
	flags.h = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.lo = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.i = i;
	flags.fd = fd;
	return (flags);
}

int			valid_conversion(const char *format, int i)
{
	while (is_flag(format[i]))
		i++;
	while ('0' <= format[i] && format[i] <= '9')
		i++;
	if (format[i] == '.')
	{
		i++;
		while ('0' <= format[i] && format[i] <= '9')
			i++;
	}
	i = is_modifier(format, i);
	return (is_conversion(format[i]));
}
