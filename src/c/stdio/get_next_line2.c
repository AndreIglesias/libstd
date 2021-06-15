/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:51:07 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/14 23:06:22 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fstrdup(const char *s1, char *pitcher)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = s1[i];
		i--;
	}
	free(pitcher);
	return (str);
}

static char	*fill_pitcher(const int fd, char *pitcher)
{
	char	guacal[BUFF_SIZE + 1];
	int		last;

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, guacal, 0))
		return (0);
	if (pitcher == NULL)
		pitcher = ft_strnew(1);
	while (!(ft_strchr(pitcher, '\n')))
	{
		last = ft_read(fd, guacal, BUFF_SIZE);
		if (last < 0)
			return (0);
		guacal[last] = '\0';
		pitcher = ft_fstrjoin(pitcher, guacal);
		if (!last || !pitcher[0])
			break ;
	}
	return (pitcher);
}

int			get_next_line2(const int fd, char **line, char **pitcher)
{
	char		*tmp;
	int			carret;

	if (!line || !(*pitcher = fill_pitcher(fd, *pitcher)))
		return (-1);
	if ((tmp = ft_strchr(*pitcher, '\n')) != 0)
	{
		carret = tmp - (*pitcher);
		if (!(*line = ft_strndup(*pitcher, carret)))
			return (-1);
		*pitcher = ft_fstrdup(tmp + 1, *pitcher);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(*pitcher)))
			return (-1);
		free(*pitcher);
		*pitcher = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}
