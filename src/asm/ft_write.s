;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/24 21:11:17 by ciglesia          #+#    #+#              ;
;    Updated: 2021/04/25 18:15:21 by ciglesia         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%ifdef __LINUX__
	%define M_FT_WRITE ft_write
	%define	M_CODE 0x0000001
	%define M_ERRNO __errno_location
	%define	M_EXTERN_CALL_SUFFIX wrt ..plt
%else
	%define M_FT_WRITE _ft_write
	%define	M_CODE 0x2000004
	%define M_ERRNO ___error
	%define	M_EXTERN_CALL_SUFFIX
%endif

global M_FT_WRITE

extern M_ERRNO

section .text

M_FT_WRITE:						; ssize_t write(int fd, const void *buf, size_t count)
								; fd = rdi, buf = rsi, count = rdx
	mov		rax, M_CODE
	syscall						; call rax (write)

%ifdef __LINUX__
	cmp		rax, 0
	jl		.error
%else
	jc		.error				; write sets carry 1 on error
%endif

	jmp .end

.error:
%ifdef __LINUX__
	neg		rax
%endif
	push	rax
	call	M_ERRNO M_EXTERN_CALL_SUFFIX
	pop		qword [rax]
	mov		rax, -1
	ret

.end:
	mov		rax, rdx
	ret
