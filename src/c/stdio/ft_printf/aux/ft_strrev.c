/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 00:10:25 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:15:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strrevf(char *str, int size)
{
	int		i;
	char	temp;
	char	*copy;

	if (!(copy = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strcpy(copy, str);
	i = 0;
	size--;
	while (size > i)
	{
		temp = copy[size];
		copy[size] = copy[i];
		copy[i] = temp;
		i++;
		size--;
	}
	free(str);
	str = copy;
	return (str);
}

int			put_wchar(char c, t_flags flags)
{
	int nb;

	nb = 0;
	if (!flags.minus && flags.width - 1 > 0)
		nb += ft_repet_fd(' ', flags.width - 1, flags.fd);
	nb += write(flags.fd, &c, 1);
	if (flags.minus && flags.width - 1 > 0)
		nb += ft_repet_fd(' ', flags.width - 1, flags.fd);
	return (nb);
}

int			di_lenp(long long int lg, t_flags flags)
{
	int				i;
	int				p;
	int				iszero;
	unsigned int	x;

	p = flags.precision;
	i = 0;
	iszero = (lg == 0) ? 1 : 0;
	if (flags.type != 'u' && lg < 0)
		lg *= -1;
	x = (unsigned int)lg;
	while (x != 0)
	{
		i++;
		x /= 10;
	}
	if (p > i)
		return (p - i - iszero);
	return (0);
}
