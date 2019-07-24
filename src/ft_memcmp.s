section .text
	global _ft_memcmp

_ft_memcmp:					; int memcmp(const void *s1, const void *s2)

	enter 0x10, 0

	cmp rdx, 0				; check n == 0 ?
	je _done

	cmp rsi, rdi			; s1 == s2?
	je _done

	mov rcx, 0				; zero out counter
	mov rax, 0

_cmp_byte:
	mov al, byte[rdi + rcx]	; put current s1 char in scratch
	mov bl, byte[rsi + rcx] ; put current s2 char in scratch

	cmp rcx, rdx
	je _cmp_end

	cmp al, bl								; *s1 != *s2 ?
	jne _cmp_end

	inc rcx
	jmp _cmp_byte

_cmp_end:
	sub al, bl
	movsx rax, al

_done:
	leave
	ret