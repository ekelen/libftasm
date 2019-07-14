extern _ft_isdigit
extern _ft_isalpha

section .text

global _ft_isalnum
_ft_isalnum:				; int		ft_isalnum(int c)

	call _ft_isalpha	; c is alpha ?
	cmp rax, 1
	je _is_alnum

	call _ft_isdigit	; c is digit ?
	cmp rax, 1
	je _is_alnum

	jmp _not_alnum

_is_alnum:
	mov rax, 1
	ret

_not_alnum:
	mov rax, 0
	ret