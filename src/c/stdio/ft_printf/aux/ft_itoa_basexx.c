/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_basexx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:11:20 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 19:28:39 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_number(uintmax_t value, int base)
{
	int	i;

	i = 0;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

static int	to_string(uintmax_t value, char *result, char *basee, int base)
{
	int			i;
	uintmax_t	x;

	i = 0;
	x = value;
	while (x != 0)
	{
		result[i] = basee[x % base];
		x /= base;
		i++;
	}
	return (i);
}

static void	create_base(int base, char *basee, int mayus)
{
	int	i;
	int	upcase;

	upcase = 87;
	if (mayus)
		upcase = 55;
	i = 0;
	while (i < base)
	{
		if (i > 9)
			basee[i] = i + upcase;
		else
			basee[i] = i + 48;
		i++;
	}
	basee[i] = '\0';
}

char	*ft_itoa_basexx(uintmax_t value, int base, int mayus)
{
	char	*basee;
	char	*result;
	int		i;

	if ((2 <= base && base <= 16))
	{
		if (value == 0)
			return ("0");
		basee = (char *)malloc(sizeof(char) * (base + 1));
		create_base(base, basee, mayus);
		i = size_number(value, base);
		result = (char *)malloc(sizeof(char) * (i + 2));
		if (!result)
			return (0);
		i = to_string(value, result, basee, base);
		result[i] = '\0';
		free(basee);
		return (ft_strrevf(result, i));
	}
	return (0);
}
