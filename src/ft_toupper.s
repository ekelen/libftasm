%define a 0x61
%define z 0x7a
%define OFFSET_UPPER 32

section .text
	extern _ft_isdigit
	extern _ft_isalpha
	global _ft_toupper

_ft_toupper:						; int ft_toupper(int c)

	cmp edi, a						; c < 'a' ?
	jl _not_lc_alpha

	cmp edi, z						; c > 'z' ?
	jg _not_lc_alpha

	jmp _is_lc_alpha

_is_lc_alpha:
	mov ecx, edi
	sub ecx, OFFSET_UPPER	; modify to uppercase letter
	mov eax, ecx
	jmp _return

_not_lc_alpha:
	mov eax, edi					; return original value
	jmp _return

_return:
	ret