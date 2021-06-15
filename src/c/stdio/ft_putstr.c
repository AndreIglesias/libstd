/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:43:50 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 21:59:02 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

int		ft_putstr(const char *str)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		ft_write(1, str, i);
		return (i);
	}
	return (0);
}
