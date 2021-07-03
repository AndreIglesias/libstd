/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:51:02 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/03 12:23:38 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTD_H
# define LIBSTD_H

# include "libtypes.h"

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
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

# define BOLD "\e[1m"
# define DIM "\e[2m"
# define ITALIC "\e[3m"
# define UNDERL "\e[4m"
# define BLINK "\e[5m"
# define REVER "\e[7m"
# define INVIS "\e[8m"
# define RED "\e[38;2;255;0;0m"
# define BLACK "\e[38;2;0;0;0m"
# define CEL "\e[38;2;114;159;207m"
# define GREEN "\e[92m"
# define CYAN "\e[38;5;31m"
# define BLUE "\e[34m"
# define YELLOW "\e[33m"
# define BLACKB "\e[40m"
# define GRAY "\e[38;5;236m"
# define LIGHT_GRAY "\e[90m"

# define BG_LIGHT_GRAY "\e[100m"
# define BG_CYAN "\e[48;5;31m"
# define BG_GRAY "\e[48;5;236m"
# define BG_E0M "\e[49m"
# define COLOR_E0M "\e[39m"
# define E0M "\e[0m"
# define LOCK "\uE0A2"
# define ARROW "\uE0B0"

/*
**	ASM
*/

/*
**		unistd
*/

ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);

/*
**	C
*/

/*
**		stdio
*/

int			ft_printf_fd(const int fd, const char *format, ...)
			__attribute__((format(printf, 2, 3)));
int			ft_printf(const char *format, ...)
			__attribute__((format(printf, 1, 2)));

int			ft_repet(char c, int i);
int			ft_repet_fd(char c, int i, const int fd);
int			ft_putchar_fd(char c, int fd);
int			ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putnbr_fd(int nb, int fd);
int			ft_putnbr_max(t_uintmax_t x, int fd);
int			ft_puterr(const char *s, int ex);
int			ft_putstr(const char *str);
int			ft_putstr_fd(const char *s, int fd);
int			get_next_line(const int fd, char **line);
int			get_next_line2(const int fd, char **line, char **pitcher);

/*
**		stdlib
*/

t_intmax_t	ft_abs(t_intmax_t x);
int			ft_atoi(const char *str);
int			ft_atoi_protected(const char *str);
char		*ft_itoa(int n);
void		*ft_calloc(size_t nmemb, size_t size);

/*
**		other
*/

#endif
