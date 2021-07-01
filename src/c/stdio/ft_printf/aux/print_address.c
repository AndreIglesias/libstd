/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:04:45 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 20:43:47 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int n)
{
	if (0 <= n && n <= 9)
		return ('0' + n);
	return ('a' + n - 10);
}

int	a_size(int i, unsigned long p, int *zeroes)
{
	int	count;
	int	zcount;

	count = 0;
	*zeroes = 0;
	zcount = 0;
	while (i >= 0)
	{
		if ((p >> i & 0xf))
		{
			if (!zcount)
				*zeroes = -1;
			else if (!(*zeroes))
				*zeroes = zcount;
		}
		else
			zcount++;
		count++;
		i -= 4;
	}
	if (!p)
		count = 0;
	if (!*zeroes)
		return (count);
	return (count - *zeroes);
}

int	ft_width(t_flags flags, int size, int g)
{
	int	nb;
	int	mprec;

	nb = 0;
	mprec = size;
	if (flags.precision > size)
		mprec = flags.precision;
	if (!flags.minus && !size)
	{
		nb += ft_repet_fd(' ', flags.width - 3 + g - flags.precision, flags.fd);
		return (nb + write(flags.fd, "0x0", 3 - g) + ft_repet_fd('0',
				flags.precision - 1, flags.fd));
	}
	if (!flags.minus)
		return (ft_repet_fd(' ', flags.width - mprec
				- flags.space - flags.plus - 2, flags.fd));
	if (!size)
	{
		nb += write(flags.fd, "0x0", 3 - g)
			+ ft_repet_fd('0', flags.precision - 1, flags.fd);
		return (nb + ft_repet_fd(' ', flags.width - 3 + g - flags.precision,
				flags.fd));
	}
	return (nb + ft_repet_fd(' ', flags.width - mprec
			- flags.space - flags.plus - 2, flags.fd));
}

int	ft_zero(t_flags flags, int size)
{
	int	nb;
	int	mprec;

	if (!size)
		return (0);
	mprec = size;
	if (flags.precision > size)
		mprec = flags.precision;
	nb = ft_repet_fd('0', flags.width - mprec - flags.space
			- flags.plus - 2, flags.fd);
	return (nb);
}

int	print_address(unsigned long p, t_flags flags, int size, int npre)
{
	int	i;
	int	nb;
	int	z;

	i = (sizeof(p) << 3) - 20;
	size = a_size(i, p, &z);
	nb = write(flags.fd, " ", 1 * (flags.space && size));
	if (!flags.minus && (!(flags.zero && !flags.precision) || !size))
		nb += ft_width(flags, size, npre);
	nb += write(flags.fd, "+", 1 * (flags.plus && size));
	if (size)
		nb += write(flags.fd, "0x", 2);
	if (!flags.minus && (flags.zero && !flags.precision) && size)
		nb += ft_zero(flags, size);
	if (size)
		nb += ft_repet_fd('0', flags.precision - size, flags.fd);
	while (size && i >= 0)
	{
		if (z-- <= 0)
			nb += ft_putchar_fd(hex_digit((p >> i) & 0xf), flags.fd);
		i -= 4;
	}
	if (flags.minus)
		nb += ft_width(flags, size, npre);
	return (nb);
}
