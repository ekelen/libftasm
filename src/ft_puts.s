%define SYSCALL_WRITE 0x2000004
%define STDOUT 1

section .data
	nl: db 0x0a				; \n character
	null_info: db "(null)", 0x0a, 0

section .text
	extern _ft_strlen
	global _ft_puts

_ft_puts:						; int ft_puts(const char *s)

	push rbp
	mov rbp, rsp
	sub rsp, 8

	cmp rdi, 0					; s == null pointer?
	je _put_null

	push rdi					; save s

	call _ft_strlen

	mov rdx, rax				; how many bytes to write
	pop rsi						; addr of s
	mov rdi, STDOUT

	mov rax, SYSCALL_WRITE
	syscall

	jc _done				; write error
	jmp _put_nl

_put_null:
	xor rdi, rdi
	mov rdi, STDOUT
	lea rsi, [rel null_info]
	mov rdx, 8
	mov rax, SYSCALL_WRITE
	syscall

	jmp _no_string


_put_nl:
	mov rdi, 1				; how many bytes to write
	lea rsi, [rel nl]		; newline
	mov rdx, STDOUT			; which file descriptor
	mov rax, SYSCALL_WRITE
	syscall

	jc _done				; if err

	mov rax, 10				; if ok
	jmp _done

_no_string:
	mov rax, 10
	jmp _done

_done:
	leave
	ret

