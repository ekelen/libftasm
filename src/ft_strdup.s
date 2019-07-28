section .text
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc
	global _ft_strdup

_ft_strdup:					; char *ft_strdup(const char *s1)
	push rbp
	mov rbp, rsp
	sub rsp, 8			

	push rdi					; save s1

	call _ft_strlen

	inc rax						; add 1 for \0
	push rax					; save strlen
	mov rdi, rax				; prepare to send to malloc

	call _malloc

	; set up vars for call to memcpy
	mov rdi, rax				; malloc return val -> dst
	pop rdx 					; pop saved strlen + 1 -> n
	pop rsi 					; pop saved s1 -> src

	call _ft_memcpy

_done:
	leave
	ret