/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:50:39 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:14:14 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_width(t_flags flags, int p, int i, int iszero)
{
	if ((flags.type != 'f' && p <= i && p > 0) || flags.precision == 0)
		p = 0;
	return (flags.width - p - i -
			(flags.type != 'u' * (flags.plus || flags.space) + p)
			+ (flags.type != 'f' && iszero && p));
}

int	ft_fillzero(int p, t_flags flags, int i)
{
	return ((p >= 0 && !((flags.precision || flags.minus) && flags.type != 'f')
			&& flags.zero && !(p && flags.type == 'f' && flags.minus) &&
			i < flags.width) || (flags.type == 'u' && flags.precision < 0 &&
			!flags.minus && flags.zero));
}

/*
** ft_strrev.c: ft_repet
** zero flag: ignore if precision in diouxX or - flag
** count radix for f
*/

int	ft_putwidth(intmax_t lg, t_flags flags, uintmax_t x, int p)
{
	int i;
	int neg;
	int iszero;

	iszero = (lg == 0 && p >= 0) ? 1 : 0;
	i = iszero;
	neg = ((lg < 0 || flags.plus || flags.space) && flags.type != 'u') ? 0 : 1;
	neg = (flags.type == 'u' && flags.precision <= 0) ? 0 : neg;
	if (flags.type != 'u' && lg < 0)
		lg *= -1;
	x = (lg == 0 && flags.type == 'u' && flags.precision != 0) ? 1 :
		(uintmax_t)lg;
	while (x != 0 && ++i)
		x /= 10;
	i += (flags.type == 'f' && (p != 0 || flags.square)) ? 1 : 0;
	if (ft_countchr("csp", flags.type) != 0)
		return (0);
	i = (flags.type != 'f' && p > i) ? iszero : i;
	iszero = (p >= 0) ? neg + u_width(flags, p, i, iszero)
		: flags.width - i - (flags.plus || flags.space) + (flags.type != 'f'
															&& iszero);
	if (ft_fillzero(p, flags, i))
		return (ft_repet_fd('0', iszero, flags.fd));
	i = (p > i) ? p : i;
	return (((flags.width - i) > 0) ? ft_repet_fd(' ', iszero, flags.fd) : 0);
}
