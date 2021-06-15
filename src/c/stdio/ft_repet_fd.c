/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repet_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:12:42 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 13:25:27 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

int	ft_repet_fd(char c, int i, const int fd)
{
	int nb;

	nb = 0;
	while (nb < i)
		nb += ft_write(fd, &c, 1);
	return (nb);
}
