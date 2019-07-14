%define A 0x41
%define Z 0x5a
%define a 0x61
%define z 0x7a

section .text
	global _ft_isalpha

_ft_isalpha:		; int ft_isalpha(int c)

	cmp rdi, A		; c < 'A' ?
	jl _not_alpha

	cmp rdi, z		; c > 'z' ?
	jg _not_alpha

	cmp rdi, Z		; c <= 'Z' ?
	jle _is_alpha

	cmp rdi, a		; c >= 'a' ?
	jge _is_alpha

	jmp _not_alpha

_is_alpha:
	mov rax, 1
	jmp _return

_not_alpha:
	mov rax, 0
	jmp _return

_return:
	ret