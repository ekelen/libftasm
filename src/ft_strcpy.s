section .text
	extern _ft_strlen
	extern _ft_memcpy
	global _ft_strcpy

_ft_strcpy:					; char *ft_strcpy(char *dst, const char *src);
	push rbp
	mov rbp, rsp
	sub rsp, 8
	push rdi					; save dst

	mov rdi, rsi			; prepare ft_strlen args
	push rsi					; save src

	call _ft_strlen
	inc rax 					; add 1 for '\0'

	pop rsi						; prepare ft_memcpy args
	pop rdi
	mov rdx, rax

	call _ft_memcpy

_return:
	leave
	ret