/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <ciglesia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:26:11 by user              #+#    #+#             */
/*   Updated: 2020/08/25 17:30:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putoxx(t_flags flags, char *s, int n, int b)
{
	int nb;

	nb = 0;
	if (!flags.minus)
	{
		if (flags.zero && flags.precision <= 0)
		{
			if (ft_strcmp(s, "0") == 0)
				nb += write(flags.fd, "00", 2);
			else
				nb += write(flags.fd, ((flags.type == 'x') ? "0x" : "0X"), 2 *
							((flags.type == 'x' || flags.type == 'X') &&
							flags.square));
			nb += ft_repet_fd('0', n - (ft_strcmp(s, "0") == 0) * 2, flags.fd);
		}
		else
			nb += ft_repet_fd(' ', n, flags.fd);
	}
	nb += (b && flags.type == 'o' && ft_strcmp(s, "0") != 0) ?
		write(flags.fd, "0", 1) : 0;
	if (b && ft_strcmp(s, "0") && (flags.type == 'x' || flags.type == 'X') &&
		!(flags.zero && flags.precision <= 0 && !flags.minus))
		nb += write(flags.fd, ((flags.type == 'x') ? "0x" : "0X"), 2);
	return (nb);
}
