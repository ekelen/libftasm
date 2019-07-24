section .text
	extern _ft_strcmp
	global _ft_strequ

_ft_strequ:				; int ft_strequ(char const *s1, char const *s2)
	enter 0x10, 0

	mov rax, 0

	call _ft_strcmp
	cmp rax, 0
	je _equal

_not_equal:
	mov rax, 0
	jmp _return

_equal:
	mov rax, 1
	jmp _return

_return:
	leave
	ret