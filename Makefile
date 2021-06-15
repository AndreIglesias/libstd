#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2021/06/14 22:53:28 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libstd.a

INCLUDE		=	./include/

#***************** DIR ********************#

DIRSRC		=	./src/
DIRC		=	$(DIRSRC)/c
DIRASM		=	$(DIRSRC)/asm

DIRIO		=	$(DIRC)/stdio
DIRLIB		=	$(DIRC)/stdlib

DIRPF		=	$(DIRIO)/ft_printf
DIRPFA		=	$(DIRPF)/aux

#***************** SRC ********************#

SRCIO		=	ft_repet.c ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putnbr_max.c ft_putstr_fd.c ft_putstr.c ft_puterr.c
SRCLIB		=	ft_abs.c ft_atoi.c ft_atoi_protected.c ft_itoa.c

SRCPF		=	caster.c ft_printf.c ft_vfprintf.c id_format.c interpreter.c manipulation.c printform.c
SRCPFA		=	ft_itoa_basexx.c ft_put.c ft_putdbl.c ft_putoxx.c ft_strrev.c print_address.c

SRCC		=	$(SRCIO) $(SRCLIB) $(SRCPF) $(SRCPFA)

SRCASM		=	ft_read.s ft_write.s

#***************** DEPS ******************#

DIROBJ		=	./depo/

CAUX		=	$(SRCC:%=$(DIROBJ)%)
ASMAUX		=	$(SRCASM:%=$(DIROBJ)%)
DEPS		=	$(ASMAUX:.s=.d) $(CAUX:.c=.d)
OBJS		=	$(ASMAUX:.s=.o) $(CAUX:.c=.o)

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

OS			=	$(shell uname)
ifeq ($(OS), Linux)
	NASM	=	/usr/bin/nasm -f elf64 -D__LINUX__=1
else
	NASM	=	/usr/bin/nasm -f macho64
endif

CC			=	/usr/bin/clang
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e
BOLD		=	"\e[1m"
BLINK		=	 "\e[5m"
RED			=	 "\e[38;2;255;0;0m"
GREEN		=	 "\e[92m"
BLUE		=	 "\e[34m"
YELLOW		=	 "\e[33m"
E0M			=	 "\e[0m"

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRASM)/%.s
				@printf $(GREEN)"Generating libelf asm objects... %-33.33s\r" $@
				@$(NASM) $< -o $@

%.o		:		../$(DIRIO)/%.c
				@printf $(GREEN)"Generating libelf c objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLIB)/%.c
				@printf $(GREEN)"Generating libelf c objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRPF)/%.c
				@printf $(GREEN)"Generating libelf c objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRPFA)/%.c
				@printf $(GREEN)"Generating libelf c objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@$(ECHO)
				@$(ECHO) $(BOLD)$(GREEN)'> Compiled'$(E0M)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@$(ECHO) $(BOLD)$(RED)'> Directory cleaned'$(E0M)

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) $(BOLD)$(RED)'> Remove executable'$(E0M)

apt		:
				sudo apt install -y clang nasm

re		:		fclean all

.PHONY	:		all clean re

-include $(DEPS)