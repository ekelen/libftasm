section .text
	global _ft_isascii

_ft_isascii:		; int isascii(int c)

	cmp edi, 0x0	; c < 0 (least ascii char) ?
	jl _not_ascii

	cmp edi, 0x7f	; c > 0x7f (greatest ascii char) ?
	jg _not_ascii

	jmp _is_ascii

_is_ascii:
	mov rax, 1
	jmp _return

_not_ascii:
	mov rax, 0
	jmp _return

_return:
	ret