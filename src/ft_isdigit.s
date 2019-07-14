section .text
	global _ft_isdigit

_ft_isdigit:		; int isdigit(int c)

	cmp rdi, 0x30	; c < '0' ?
	jl _not_digit

	cmp rdi, 0x39	; c > '9' ?
	jg _not_digit

is_digit:
	mov rax, 1
	jmp _return

_not_digit:
	mov rax, 0
	jmp _return

_return:
	ret