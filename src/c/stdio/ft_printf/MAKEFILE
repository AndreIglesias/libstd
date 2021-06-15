#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:53:05 by ciglesia          #+#    #+#              #
#    Updated: 2020/09/01 01:55:49 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a
DIRSRC		=	./src/
DIRAUX		=	./src/aux/
DIRAUX2		=	../
DIROBJ		=	./depo/
INCLUDE		=	./include/
INCLUDE2	=	../include/
SRC			=	ft_printf.c caster.c ft_vfprintf.c id_format.c interpreter.c manipulation.c
AUX			=	ft_put.c print_address.c ft_strrev.c ft_putdbl.c printform.c ft_putoxx.c ft_itoa_basexx.c
AUX2		=	ft_atoi.c ft_strcmp.c ft_countchr.c ft_itoa.c ft_strcpy.c ft_strlen.c ft_putchar_fd.c ft_putnbr_max.c ft_abs.c ft_repet_fd.c
OAUX		=	$(SRC:%=$(DIROBJ)%) $(AUX:%=$(DIROBJ)%) $(AUX2:%=$(DIROBJ)%)
OBJS		= 	$(OAUX:.c=.o)
DEPS		= 	$(OAUX:.c=.d)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e


%.o		:		../$(DIRSRC)%.c
				$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRAUX)%.c
				$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRAUX2)%.c
				$(CC) $(CFLAGS) -I $(INCLUDE2) -MMD -o $@ -c $<


$(NAME)	:		$(OBJS)
				@ar rc $(NAME) $(OBJS)
				ranlib $(NAME)
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				-@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

-include $(DEPS)
