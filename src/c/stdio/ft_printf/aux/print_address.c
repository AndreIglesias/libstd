/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:04:45 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:26:46 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int n)
{
	return (0 <= n && n <= 9) ? ('0' + n) : ('a' + n - 10);
}

int		a_size(int i, unsigned long p, int *zeroes)
{
	int count;
	int zcount;

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
	return (((!*zeroes) ? count : count - *zeroes));
}

int		ft_width(t_flags flags, int size, int npre)
{
	int nb;

	nb = 0;
	if (!flags.minus)
	{
		if (!size)
		{
			nb += ft_repet_fd(' ', flags.width - 3 + npre - flags.precision,
				flags.fd);
			return (nb + write(flags.fd, "0x0", 3 - npre) + ft_repet_fd('0',
					flags.precision - 1, flags.fd));
		}
		return (ft_repet_fd(' ', flags.width - ((flags.precision > size)
		? flags.precision : size) - flags.space - flags.plus - 2, flags.fd));
	}
	if (!size)
	{
		nb += write(flags.fd, "0x0", 3 - npre) +
			ft_repet_fd('0', flags.precision - 1, flags.fd);
		return (nb + ft_repet_fd(' ', flags.width - 3 + npre - flags.precision,
				flags.fd));
	}
	return (nb + ft_repet_fd(' ', flags.width - ((flags.precision > size)
		? flags.precision : size) - flags.space - flags.plus - 2, flags.fd));
}

int		ft_zero(t_flags flags, int size)
{
	if (!size)
		return (0);
	return (ft_repet_fd('0', flags.width -
			((flags.precision > size)
			? flags.precision : size)
			- flags.space - flags.plus - 2, flags.fd));
}

int		print_address(unsigned long p, t_flags flags, int size, int npre)
{
	int i;
	int nb;
	int z;

	i = (sizeof(p) << 3) - 20;
	size = a_size(i, p, &z);
	nb = (flags.space && size) ? write(flags.fd, " ", 1) : 0;
	if (!flags.minus && (!(flags.zero && !flags.precision) || !size))
		nb += ft_width(flags, size, npre);
	nb += (flags.plus && size) ? write(flags.fd, "+", 1) : 0;
	nb += (size) ? write(flags.fd, "0x", 2) : 0;
	if (!flags.minus && (flags.zero && !flags.precision) && size)
		nb += ft_zero(flags, size);
	nb += ft_repet_fd('0', (!size) ? 0 : flags.precision - size, flags.fd);
	while (size && i >= 0)
	{
		if (z-- <= 0)
			nb += ft_putchar_fd(hex_digit((p >> i) & 0xf), flags.fd);
		i -= 4;
	}
	nb += (flags.minus) ? ft_width(flags, size, npre) : 0;
	return (nb);
}
