/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:43:54 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 21:34:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	lg;

	lg = nb;
	if (lg == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		lg = 147483648;
		ft_putnbr_fd(lg, fd);
	}
	else if (lg < 0)
	{
		ft_putchar_fd('-', fd);
		lg *= -1;
		ft_putnbr_fd(lg, fd);
	}
	else if (lg >= 10)
	{
		ft_putnbr_fd(lg / 10, fd);
		ft_putchar_fd(lg % 10 + 48, fd);
	}
	else if (lg < 10)
		ft_putchar_fd(lg % 10 + '0', fd);
}
