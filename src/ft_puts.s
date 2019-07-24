%define SYSCALL_WRITE 0x2000004
%define STDOUT 1

section .data
	nl: db 0x0a				; \n character

section .text
	extern _ft_strlen
	global _ft_puts

_ft_puts:						; int ft_puts(const char *s)

	enter 0x10, 0

	cmp rdi, 0				; s is null ptr ?
	je _no_string

	push rdi					; save s

	call _ft_strlen

	mov rdx, rax			; how many bytes to write
	pop rsi						; addr of s
	mov rdi, STDOUT

	mov rax, SYSCALL_WRITE
	syscall

	cmp rax, -1				; check if write error
	je _done

put_nl:
	mov rdi, 1				; how many bytes to write
	lea rsi, [rel nl]	; newline
	mov rdx, 1				; which file descriptor

	mov rax, SYSCALL_WRITE
	syscall

	cmp rax, -1
	je _done

	mov rax, 1				; ok
	jmp _done

_no_string:
	mov rax, 0
	jmp _done

_done:
	leave
	ret

