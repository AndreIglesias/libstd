/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:09:21 by ciglesia          #+#    #+#             */
/*   Updated: 2020/07/19 18:20:35 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int(t_flags flags, va_list ap)
{
	intmax_t x;

	if (flags.l)
		return (va_arg(ap, long int));
	else if (flags.ll)
		return (va_arg(ap, long long int));
	else
		x = (va_arg(ap, int));
	if (flags.hh)
		x = (signed char)x;
	else if (flags.h)
		return (short int)x;
	return (x);
}

uintmax_t	flags_uoxx(t_flags flags, va_list ap)
{
	uintmax_t x;

	if (flags.l)
		return (va_arg(ap, unsigned long int));
	else if (flags.ll)
		return (va_arg(ap, unsigned long long int));
	else
		x = (va_arg(ap, unsigned int));
	if (flags.hh)
		x = (unsigned char)x;
	else if (flags.h)
		x = (unsigned short int)x;
	return (x);
}
