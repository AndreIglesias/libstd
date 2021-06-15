/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:03:41 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 21:35:50 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

int	ft_putnbr_max(t_uintmax_t x, int fd)
{
	if (x >= 10)
		return (ft_putnbr_max(x / 10, fd) + ft_putchar_fd(x % 10 + 48, fd));
	else
		return (ft_putchar_fd(x + 48, fd));
}
