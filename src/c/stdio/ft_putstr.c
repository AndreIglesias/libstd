/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:43:50 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 19:10:31 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

int	ft_putstr(const char *str)
{
	int	i;

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
