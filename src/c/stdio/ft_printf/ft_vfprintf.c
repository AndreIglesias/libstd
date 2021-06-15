/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:34:38 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 16:50:34 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** conversion specification:
**	%[flag/s][min field width][precision][length modifier]<conversion specifier>
**		or
**	%<m$>[flag/s][*m$][.*m$][length mod]<conversion specifier> (not handeled)
*/

#include "ft_printf.h"

/*
** id_format.c: init_flags
** interpreter.c: ft_flags, no_flags, ft_modifiers
*/

t_flags		interpret(const char *format, int i, int fd)
{
	t_flags flags;

	flags = init_flags(i, fd);
	flags = ft_flags(format, flags);
	flags = no_flags(format, flags);
	flags = ft_modifiers(format, flags, flags.i - 1);
	flags.type = format[flags.i++];
	manage_exceptions(&flags);
	return (flags);
}

/*
** id_format.c: valid_conversion
** manipulation.c: manipulation
*/

int			vprint(const char *format, t_fdi fdi, va_list ap, int *res)
{
	t_flags flags;

	if ((valid_conversion(format, fdi.i)) ? 1 : 0)
	{
		flags = interpret(format, fdi.i, fdi.fd);
		*res += manipulation(flags, ap);
		return (flags.i);
	}
	*res += write(fdi.fd, "%", 1);
	return (fdi.i);
}

int			ft_vfprintf(const char *format, va_list ap, int fd)
{
	int		i;
	int		res;
	t_fdi	fdi;

	res = 0;
	i = 0;
	fdi.fd = fd;
	while (format[i])
	{
		if (format[i] == '%')
		{
			fdi.i = i + 1;
			i = vprint(format, fdi, ap, &res);
		}
		else if (format[i] == '\\' && format[i + 1])
		{
			res += write(fd, &format[i], 2);
			i += 2;
		}
		else
			res += write(fd, &format[i++], 1);
	}
	return (res);
}
