/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:03:16 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/02 18:32:13 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstd.h"
#include "libstring.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*mem;

	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
