/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:48 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 21:21:49 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"

static int	size_number(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	expion(int n, int i, char *result)
{
	if (n == 0)
	{
		result[i] = '0';
		i++;
	}
	return (i);
}

static void	res(int i, int sign, char temp, char *result)
{
	while (i > sign)
	{
		temp = result[i];
		result[i] = result[sign];
		result[sign] = temp;
		sign++;
		i--;
	}
}

static int	to_string(int n, char *result, int i, char *base)
{
	while (n != 0)
	{
		result[i] = base[ft_abs(n % 10)];
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*result;
	char	*base;
	int		i;
	char	temp;

	base = "0123456789";
	temp = (n == -2147483648) ? 'b' : '\0';
	sign = (n < 0 && temp != 'b') ? -1 : 1;
	n = (n < 0 && temp != 'b') ? -n : n;
	result = malloc(sizeof(char) * (size_number(n) + 1));
	if (!result)
		return (NULL);
	i = expion(n, 0, result);
	i = to_string(n, result, i, base);
	if (sign < 0 || temp == 'b')
	{
		result[i] = '-';
		i++;
	}
	result[i] = '\0';
	res(i - 1, 0, temp, result);
	return (result);
}
