/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 02:04:42 by ciglesia          #+#    #+#             */
/*   Updated: 2020/07/12 19:26:15 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**%[flag/s][min field width][precision][length modifier]  <conversion specifier>
**%[#0-+ ] [decimal]    [. or .decimal]    [hh h l ll L]  <diouxXcspf%>
**	conversions
**		csp
**		diouxX	[hh h l ll]
**		f	[l L]
**		%%
**	flags
**		#
**		0
**		-
**		+
**		espace
**	#
**		o	prefix 0 if nonzero
**		xX	prefix 0x 0X if nonzero
**		f	decimal point even if no decimals
**	0
**		diouxXf		prefix 0 instead of spaces
**		ignore		if precision in diouxX or - flag
**	-
**		left-justify
**		pad right with space instead left 0s or spaces
**	+
**		sign number even if non negative
**	space
**		blank space before value or empty string
**		ignore if + flag
**	min field width
**		pad with spaces on the left (or right if -)
**		if conversion with is smaller
**	precision
**		diouxX	min number of digits to appear
**		f	min number of ... after radix
**		s	max number of characters to print
**		.	precision of 0
**		A precision of 0 means that no character is written for the value 0
*/

int		thereis_flag(t_flags flags)
{
	return (flags.h || flags.hh || flags.ll || flags.l || flags.lo);
}

/*
** printform.c: print_arg
*/

int		manipulation(t_flags flags, va_list ap)
{
	if (ft_countchr("diouxX", flags.type) > 0 && flags.lo != 0)
		return (0);
	if (flags.type == 'f' && (flags.h || flags.hh || flags.ll))
		return (0);
	return (print_arg(flags, ap));
}
