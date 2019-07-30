section .text
	global _ft_memcpy

_ft_memcpy:			; void *ft_memcpy(void *dst, const void *src, size_t n)

	push rbp
	mov rbp, rsp
	sub rsp, 8

	push rdi		; save dst

	mov rax, rsi	; src to rax
	mov rcx, rdx	; n to counter

	cld				; clear direction flag:
					;	in string scan ops,
					;	increment byte[rdi] and byte[rsi]

	rep movsb		; rep:
							;		repeat rcx times
							; movsb:
							;		store byte[rsi] into byte[rdi]
							;		increment di and si

_done:
	pop rax			; return saved dst
	leave

_return:
	ret