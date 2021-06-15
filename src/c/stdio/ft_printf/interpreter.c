/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 02:25:56 by ciglesia          #+#    #+#             */
/*   Updated: 2020/07/12 19:24:51 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags(const char *format, t_flags flags)
{
	int i;

	i = flags.i - 1;
	while (is_flag(format[++i]))
	{
		if (format[i] == '#')
			flags.square = 1;
		if (format[i] == '0')
			flags.zero = 1;
		if (format[i] == '+')
			flags.plus = 1;
		if (format[i] == '-')
			flags.minus = 1;
		if (format[i] == ' ')
			flags.space = 1;
	}
	flags.i = i;
	return (flags);
}

t_flags	ft_modifiers(const char *format, t_flags flags, int i)
{
	if (ft_countchr("hlL", format[++i]))
	{
		if (format[i] == 'l')
		{
			if (format[i + 1] && format[i + 1] == 'l')
				flags.ll = 1;
			else
				flags.l = 1;
			i = (format[i + 1] && format[i + 1] == 'l') ? i + 1 : i;
		}
		if (format[i] == 'h')
		{
			if (format[i + 1] && format[i + 1] == 'h')
			{
				i++;
				flags.hh = 1;
			}
			else
				flags.h = 1;
		}
		if (format[i++] == 'L')
			flags.lo = 1;
	}
	flags.i = i;
	return (flags);
}

t_flags	no_flags(const char *format, t_flags flags)
{
	int i;

	i = flags.i;
	flags.width = ft_atoi(&format[i]);
	while ('0' <= format[i] && format[i] <= '9')
		i++;
	if (format[i] == '.')
	{
		i++;
		flags.precision = ft_atoi(&format[i]);
		while ('0' <= format[i] && format[i] <= '9')
			i++;
	}
	flags.i = i;
	return (flags);
}

void	manage_exceptions(t_flags *flags)
{
	if ((*flags).zero &&
		(((*flags).precision > 0 && ft_countchr("diouxX", (*flags).type) > 0)
		|| (*flags).minus))
		(*flags).zero = 0;
	if ((*flags).space && (*flags).plus)
		(*flags).space = 0;
}
