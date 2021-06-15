/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:28:32 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 14:45:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

/*
**	functions dependent on libstring:
**		ft_printf / ft_printf_fd
**		get_next_line / get_next_line2
**
**	The main program has to link both the libraries and
**	it's important to link lib1 after lib2 when lib2 depends on lib1.
**	example:
**	gcc -I include main.c libstd.a ../libstring/libstring.a
*/

# define BUFF_SIZE 6

int		ft_countchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strlen(char *str);

char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
char	*ft_fstrjoin(char *s1, char *s2);

#endif
