/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:41:25 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:51:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** <man 3 printf - man 3 stdarg>
** Funct: write, malloc, free, exit, (man 3 stdarg)
** gérer conversions: csp, diouxX (hh,h,l,ll), f (l, L)
** gérer: %%, #0-+ (espace), taille minimum du champ, précision
*/

int	ft_printf_fd(const int fd, const char *format, ...)
{
	va_list	args;
	int		res;

	if (format[0] == '%' && format[1] == 0)
		return (0);
	va_start(args, format);
	res = ft_vfprintf(format, args, fd);
	va_end(args);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	if (format[0] == '%' && format[1] == 0)
		return (0);
	va_start(args, format);
	res = ft_vfprintf(format, args, 1);
	va_end(args);
	return (res);
}
