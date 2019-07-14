global _ft_isprint

section .text

_ft_isprint:		; int isprint(int c)

	cmp edi, 0x20	; c < ascii char 0x20 (space)?
	jl _not_print

	cmp edi, 0x7e	; c > ascii char 0x7e (`~`)?
	jg _not_print

	jmp _is_print

_is_print:
	mov rax, 1
	jmp _return

_not_print:
	mov rax, 0
	jmp _return

_return:
	ret