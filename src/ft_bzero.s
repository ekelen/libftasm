section .text
	global _ft_bzero

_ft_bzero:					; void bzero(void *s, size_t n)

	push rbp
	mov rbp, rsp
	sub rsp, 8

	mov rcx, 0				; initialize counter to 0

	cmp rdi, 0				; check *s isn't null
	je _done

	cmp rsi, 0				; check n > 0
	je _done

_zero_out_byte:
	mov byte [rdi + rcx], 0	; put value 0 at *s + counter

	inc rcx
	cmp rsi, rcx			; check counter == n
	je _done

	jmp _zero_out_byte

_done:
	leave
	ret
