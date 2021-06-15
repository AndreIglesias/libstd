/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:41:34 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 02:35:47 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libstring.h"
/*
**  # 0 + - <space>
**  if with or precision < 0 -> position
*/
typedef struct		s_flags
{
	int				square;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				width;
	int				precision;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				lo;
	char			type;
	int				i;
	int				fd;
}					t_flags;

typedef struct		s_fdi
{
	int				i;
	int				fd;
}					t_fdi;

int					ft_printf_fd(const int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
int					ft_vfprintf(const char *format, va_list ap, int fd);
t_flags				ft_flags(const char *format, t_flags flags);
t_flags				ft_modifiers(const char *format, t_flags flags, int i);
t_flags				no_flags(const char *format, t_flags flags);
void				manage_exceptions(t_flags *flags);
int					is_conversion(const char c);
int					is_modifier(const char *format, int i);
int					is_flag(const char c);
t_flags				init_flags(int i, int fd);
int					valid_conversion(const char *format, int i);
int					manipulation(t_flags flags, va_list ap);
int					print_di(t_flags flags, intmax_t nb, int nprecision, int d);
int					print_uoxx(t_flags flags, va_list ap, int nb, int n);
int					print_arg(t_flags flags, va_list ap);
int					di_lenp(long long int lg, t_flags flags);
intmax_t			get_int(t_flags flags, va_list ap);
uintmax_t			flags_uoxx(t_flags flags, va_list ap);

t_intmax_t			ft_abs(t_intmax_t x);
int					ft_atoi(const char *str);
int					ft_countchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
int					ft_putnbr_max(t_uintmax_t nb, int fd);
int					ft_putchar_fd(char c, const int fd);
int					ft_strlen(char *str);
char				*ft_strrevf(char *str, int size);
int					print_address(unsigned long p, t_flags flags, int size,
													int npre);
char				*ft_itoa_basexx(uintmax_t value, int base, int mayus);
int					ft_putdbl(long double d, t_flags flags);
int					ft_putoxx(t_flags flags, char *s, int n, int b);
int					ft_repet_fd(char c, int i, int fd);
int					ft_putwidth(intmax_t lg, t_flags flags, uintmax_t x, int p);
int					put_wchar(char c, t_flags flags);
#endif
