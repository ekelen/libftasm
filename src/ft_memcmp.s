%define CHAR_MIN -127

section .text
	global _ft_memcmp

_ft_memcmp:				; int ft_memcmp(const void *s1, const void *s2, size_t n)

	push rbp
	mov rbp, rsp

	cmp rdx, 0			; check n == 0 ?
	je _done

	cmp rsi, rdi		; check s1 == s2 ?
	je _done

	mov rcx, 0			; counter to 0
	mov rax, 0			; rax to 0
	mov r10, 0
	mov r11, 0

_compare_bytes:
	mov rcx, rdx	; set counter to max bytes to compare
	cld
	repe cmpsb

	movsx r10, byte[rdi - 1]	; s1 char val
	movsx r11, byte[rsi - 1]	; s2 char val

	sub r10, r11				; difference to scratch register

	cmp r10, CHAR_MIN			; ugly way to return unsigned comparison
	jl _abs
	jmp _continue

_abs:
	shl r10, 32					; shift left for unsigned char diff

_continue:
	mov rax, r10

_done:
	mov rsp, rbp
	pop rbp
	ret