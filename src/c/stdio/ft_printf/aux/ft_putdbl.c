/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 03:22:40 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:34:15 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_fmod(long double a, double b)
{
	double mod;

	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	mod = a;
	while (mod >= b)
		mod -= b;
	if (a < 0)
		return (-mod);
	return (mod);
}

static int	ft_pow(int n, int xp)
{
	int a;

	a = 1;
	while (xp > 0)
	{
		a *= n;
		xp--;
	}
	return (a);
}

int			ft_putzeroes(long double nb, int precision, int fd)
{
	int zeroes;

	nb *= ft_pow(10, precision);
	zeroes = 0;
	while ((int)nb > 1)
	{
		if (ft_fmod(nb, 10) + 1e-9 >= 1.)
			zeroes = 0;
		else
			zeroes++;
		nb /= 10.;
	}
	ft_repet_fd('0', zeroes, fd);
	return (zeroes);
}

/*
** ft_put.c: ft_putwidth
*/

int			ft_putdbl(long double d, t_flags flags)
{
	int				nb;
	long long int	a;

	nb = write(flags.fd, " ", (d >= 0 && !flags.plus && flags.space) ? 1 : 0);
	nb += write(flags.fd, "+", (d >= 0 && flags.zero) ? flags.plus : 0);
	nb += write(flags.fd, "-", (d < 0 && flags.zero) ? 1 : 0);
	if (!flags.minus)
		nb += ft_putwidth((long long)d, flags, (unsigned)d, flags.precision);
	nb += write(flags.fd, "+", (d >= 0 && !flags.zero) ? flags.plus : 0);
	nb += write(flags.fd, "-", (d < 0 && !flags.zero) ? 1 : 0);
	nb += ft_putnbr_max(ft_abs((long long int)d), flags.fd);
	a = (long long int)d;
	d *= (d < 0) ? -1 : 1;
	d -= (long double)ft_abs(a);
	nb += (flags.precision != 0 || flags.square) ? write(flags.fd, ".", 1) : 0;
	nb += ft_putzeroes(1 + ft_fmod(d, 1), flags.precision, flags.fd);
	d = (ft_fmod(d, 1)) * ft_pow(10, flags.precision);
	nb += (!d) ? ft_repet_fd('0', flags.precision, flags.fd) : 0;
	if ((int)(d * 10) % 10 >= 5)
		d++;
	if (flags.precision != 0 && d)
		nb += ft_putnbr_max((long long int)d, flags.fd);
	nb += (flags.minus) ? ft_putwidth(a, flags, (unsigned int)a,
			flags.precision) : 0;
	return (nb);
}
