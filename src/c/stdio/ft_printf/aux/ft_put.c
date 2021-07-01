/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:50:39 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 21:11:56 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_width(t_flags flags, int p, int i, int iszero)
{
	if ((flags.type != 'f' && p <= i && p > 0) || flags.precision == 0)
		p = 0;
	return (flags.width - p - i
		- (flags.type != 'u' * (flags.plus || flags.space) + p)
		+ (flags.type != 'f' && iszero && p));
}

int	ft_fillzero(int p, t_flags flags, int i)
{
	return ((p >= 0 && !((flags.precision || flags.minus) && flags.type != 'f')
			&& flags.zero && !(p && flags.type == 'f' && flags.minus)
			&& i < flags.width) || (flags.type == 'u' && flags.precision < 0
			&& !flags.minus && flags.zero));
}

static int	calc_iszero(t_flags flags, int i, int iszero)
{
	int	ret;

	ret = flags.width - i;
	ret = ret - (flags.plus || flags.space) + (flags.type != 'f' && iszero);
	return (ret);
}

static uintmax_t	calc_x(t_flags flags, intmax_t *lg, uintmax_t x, int *i)
{
	if (flags.type != 'u' && (*lg) < 0)
		(*lg) *= -1;
	x = (uintmax_t)(*lg);
	if (!(*lg) && flags.type == 'u' && flags.precision != 0)
		x = 1;
	while (x != 0 && ++(*i))
		x /= 10;
	return (x);
}

/*
** ft_strrev.c: ft_repet
** zero flag: ignore if precision in diouxX or - flag
** count radix for f
*/

int	ft_putwidth(intmax_t lg, t_flags flags, uintmax_t x, int p)
{
	int	i;
	int	neg;
	int	iszero;

	iszero = (lg == 0 && p >= 0);
	i = iszero;
	neg = !((lg < 0 || flags.plus || flags.space) && flags.type != 'u');
	neg = !(flags.type == 'u' && flags.precision <= 0) * neg;
	x = calc_x(flags, &lg, x, &i);
	i += (flags.type == 'f' && (p != 0 || flags.square));
	if (ft_countchr("csp", flags.type) != 0)
		return (0);
	if (flags.type != 'f' && p > i)
		i = iszero;
	iszero = neg + u_width(flags, p, i, iszero);
	if (p < 0)
		iszero = calc_iszero(flags, i, iszero);
	if (ft_fillzero(p, flags, i))
		return (ft_repet_fd('0', iszero, flags.fd));
	if (p > i)
		i = p;
	return (ft_repet_fd(' ', iszero * ((flags.width - i) > 0), flags.fd));
}
