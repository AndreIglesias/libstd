/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:51:02 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 15:54:00 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTD_H
# define LIBSTD_H

# include <sys/types.h>

/*
**	#define __SSIZE_T_TYPE		__SWORD_TYPE
**	__STD_TYPE __SSIZE_T_TYPE __ssize_t;
*/

/*
**	malloc
*/

# include <stdlib.h>

/*
**	Determine the wordsize from the preprocessor defines.
*/

# if defined __x86_64__ && !defined __ILP32__
#  define __WORDSIZE	64
# else
#  define __WORDSIZE	32
# endif

/*
**	Convenience types.
*/

typedef unsigned char							t__u_char;
typedef unsigned short int						t__u_short;
typedef unsigned int							t__u_int;
typedef unsigned long int						t__u_long;

# if __WORDSIZE == 64
typedef signed long int							t__int64_t;
typedef unsigned long int						t__uint64_t;
# else
__extension__ typedef signed long long int		t__int64_t;
__extension__ typedef unsigned long long int	t__uint64_t;
# endif

/*
**	quad_t is also 64 bits.
*/

# if __WORDSIZE == 64
typedef long int								t__quad_t;
typedef unsigned long int						t__u_quad_t;
# else
__extension__ typedef long long int				t__quad_t;
__extension__ typedef unsigned long long int	t__u_quad_t;
# endif

/*
**	Largest integral types.
*/

# if __WORDSIZE == 64
typedef long int								t__intmax_t;
typedef unsigned long int						t__uintmax_t;
# else
__extension__ typedef long long int				t__intmax_t;
__extension__ typedef unsigned long long int	t__uintmax_t;
# endif

typedef t__intmax_t								t_intmax_t;
typedef t__uintmax_t							t_uintmax_t;

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

int			ft_printf_fd(const int fd, const char *format, ...);
int			ft_printf(const char *format, ...);
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

/*
**		other
*/

#endif
