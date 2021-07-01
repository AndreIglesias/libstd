/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:48 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 19:09:01 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

static int	ft_intlen(long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long	nb;
	int		len;
	char	*str;
	int		i;
	int		sign;

	nb = nbr;
	len = ft_intlen(nb);
	sign = 0;
	if (nb < 0)
		sign = 1;
	str = (char *)malloc(sizeof(char) * (len + sign + 1));
	i = len + sign;
	while (i > 0)
	{
		i--;
		str[i] = (char)(ft_abs(nb % 10) + '0');
		nb /= 10;
	}
	if (sign)
		str[0] = '-';
	str[len + sign] = 0;
	return (str);
}
