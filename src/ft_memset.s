section .text
	global _ft_memset

_ft_memset:			; void *ft_memset(void *b, int c, size_t len)
	push rbp
	mov rbp, rsp
	sub rsp, 8

	push rdi		; save b
	mov rax, rsi	; c to accumulator for string scan
	mov rcx, rdx	; len to counter

	cld				; clear direction flag

	rep stosb		; rep:
							;		repeat rcx times
							; stosb:
							;		accumulator value (c) to byte[rdi] (b)
							;		increment byte[rdi] (b) pointer

_done:
	pop rax			; return saved b
	leave

_return:
	ret