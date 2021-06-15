/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:37:42 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:34:51 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** aux/ft_put.c: ft_putwidth
** aux/ft_strrev.c: di_lenp
*/

int	print_di(t_flags flags, intmax_t nb, int npre, int d)
{
	int	i;
	int p;

	i = 0;
	p = flags.precision;
	if (ft_countchr("u%", flags.type) == 0)
	{
		i += write(d, " ", (nb >= 0 && !flags.plus && flags.space) ? 1 : 0);
		i += write(d, "+", (nb >= 0 && flags.zero && !p && flags.plus) ? 1 : 0);
		i += write(d, "-", (nb < 0 && flags.zero && !p) ? 1 : 0);
	}
	if (!flags.minus)
		i += ft_putwidth(nb, flags, (unsigned int)nb, (npre) ? -1 : p);
	if (ft_countchr("u%", flags.type) == 0)
		i += write(d, "+", (nb >= 0 && (p || !flags.zero)) ? flags.plus : 0);
	if (ft_countchr("u%", flags.type) == 0)
		i += write(d, "-", (nb < 0 && (!flags.zero || p)) ? 1 : 0);
	i += (p) ? ft_repet_fd('0', di_lenp(nb, flags), d) : 0;
	if (flags.type != '%' && (nb || !npre))
		i += ft_putnbr_max((flags.type != 'u') ? ft_abs(nb) : nb, d);
	i += write(d, "%", (flags.type == '%') ? 1 : 0);
	if (flags.minus)
		i += ft_putwidth(nb, flags, (unsigned int)nb, (npre) ? -1 : p);
	return (i);
}

int	ft_uoxx_w(t_flags flags, char *s, int q, int b)
{
	int n;

	n = flags.width - ft_strlen(s) -
		((flags.type == 'o') ? b + flags.precision <= 0 && flags.square
		: b * 2 * (ft_strcmp(s, "0") != 0)) - ((q > 0) ? q : 0);
	n += (ft_strcmp(s, "0") == 0 && flags.precision == 0 &&
		!(flags.square && flags.type == 'o'));
	n += (ft_strcmp(s, "0") == 0 &&
		flags.precision == -1 && flags.type == 'o');
	return (n);
}

/*
** aux/ft_putoxx.c: ft_putoxx
*/

int	print_uoxx(t_flags flags, va_list ap, int nb, int n)
{
	char	*s;
	int		b;
	int		q;

	if (flags.type == 'o' || flags.type == 'x' || flags.type == 'X')
	{
		s = ft_itoa_basexx(flags_uoxx(flags, ap), n, (flags.type == 'X'));
		q = flags.precision - ft_strlen(s);
		b = (q > 0 && flags.type == 'o') ? 0 : flags.square;
		n = ft_uoxx_w(flags, s, q, b);
		nb += ft_putoxx(flags, s, n, b);
		nb += (q > 0) ? ft_repet_fd('0', q, flags.fd) : 0;
		nb += (ft_strcmp(s, "0") == 0 && flags.precision == 0
			&& !(flags.square && flags.type == 'o'))
			? 0 : write(flags.fd, s, ft_strlen(s));
		nb += (flags.minus) ? ft_repet_fd(' ', n, flags.fd) : 0;
		if (ft_strcmp(s, "0") != 0)
			free(s);
		return (nb);
	}
	return (print_di(flags, flags_uoxx(flags, ap),
					flags.precision == 0, flags.fd));
}

int	put_wstr(char *str, t_flags flags)
{
	int i;
	int w;
	int nb;
	int p;

	i = 0;
	nb = 0;
	if (!str)
		str = "(null)";
	p = (str) ? flags.precision : 6;
	w = flags.width;
	i = (str) ? ft_strlen(str) : 6;
	if (!flags.minus && w - ((p < i && p >= 0) ? p : i) > 0)
		nb += ft_repet_fd(' ', w -
						((p < i && p >= 0) ? flags.precision : i), flags.fd);
	if (str)
		nb += write(flags.fd, str, (p < i && p >= 0) ? p : i);
	else
		nb += write(flags.fd, (flags.precision < 0 || flags.precision > 5) ?
			"(null)" : "      ", 6);
	if (flags.minus && w - ((p < i && p >= 0) ? p : i) > 0)
		nb += ft_repet_fd(' ', w - ((p < i && p >= 0) ? p : i), flags.fd);
	return (nb);
}

/*
** aux/ft_putdbl.c: ft_putdbl
** caster.c: get_int
*/

int	print_arg(t_flags flags, va_list ap)
{
	int npr;

	if (flags.type == 'f')
	{
		flags.precision = (flags.precision >= 0) ? flags.precision : 6;
		return (ft_putdbl((flags.lo) ? va_arg(ap, long double)
				: va_arg(ap, double), flags));
	}
	if (flags.type == 's')
		return (put_wstr(va_arg(ap, char*), flags));
	npr = (flags.precision == 0);
	flags.precision = (flags.precision > 0 || ft_countchr("uoxX", flags.type))
		? flags.precision : 0;
	if (flags.type == 'd' || flags.type == 'i')
		return (print_di(flags, get_int(flags, ap), npr, flags.fd));
	if (flags.type == 'c')
		return (put_wchar((char)va_arg(ap, int), flags));
	if (flags.type == 'p')
		return (print_address((unsigned long)va_arg(ap, void*), flags, 0, npr));
	if (ft_countchr("uoxX", flags.type) > 0)
		return (print_uoxx(flags, ap, 0, (flags.type == 'o') ? 8 : 16));
	if (flags.type == '%')
		return (print_di(flags, 0, npr, flags.fd));
	return (0);
}
