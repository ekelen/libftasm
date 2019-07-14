section .text
	global _ft_strcmp

_ft_strcmp:					; int strcmp(const char *s1, const char *s2)

	mov rcx, 0				; zero out counter

	cmp rsi, rdi			; s1 == s2?
	je _done

_cmp_char:
	mov al, byte[rdi + rcx]	; put current s1 char in scratch
	mov bl, byte[rsi + rcx] ; put current s2 char in scratch

	cmp al, 0								; *s1 == 0 ?
	je _cmp_end

	cmp bl, 0								; *s2 == 0 ?
	je _cmp_end

	cmp al, bl							; *s1 != *s2 ?
	jne _cmp_end

	inc rcx
	jmp _cmp_char

_cmp_end:
	sub al, bl
	movsx rax, al

_done:
	ret