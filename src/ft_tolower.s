%define A 0x41
%define Z 0x5a
%define LOWER_OFFSET 32

section .text
	global _ft_tolower

_ft_tolower:							; int ft_tolower(int c)

	cmp edi, A							; c < 'A' ?
	jl _not_uc_alpha

	cmp edi, Z							; c > 'Z' ?
	jg _not_uc_alpha

	jmp _is_uc_alpha

_is_uc_alpha:
	mov ecx, edi
	add ecx, LOWER_OFFSET		; modify to lowercase letter
	mov eax, ecx
	jmp _return

_not_uc_alpha:
	mov eax, edi						; return original value
	jmp _return

_return:
	ret