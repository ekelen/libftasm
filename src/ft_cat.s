%define BUFSIZE 0xff
%define SYSCALL_READ 0x2000003
%define SYSCALL_WRITE 0x2000004
%define STDOUT 1
%define STDERR 2
%define ERRMSG_LEN 35
%define EOF 0
%define ERR -1

section .data
	buf: times 0xff db 0	; 255 char string of `\0`
						; don't want to make syscall too often,
						; so we create buffer
	errmsg: db 'ft_cat: No such file or directory', 0x0a, 0

section .text
	global _ft_cat

_ft_cat:							; void ft_cat(int fd)

	enter 0x10, 0

_read:
	lea rsi, [rel buf]	; memory addr of buf -> rsi
	mov rdx, BUFSIZE	; max size to read
	mov rax, SYSCALL_READ

	push rdi			; save fd

	syscall

	jc _err				; break if error (if carry flag set)

	cmp rax, EOF
	je _done				; break if EOF

_write:
	mov rdi, STDOUT
	mov rdx, rax		; num bytes to write (returned from read call)
	mov rax, SYSCALL_WRITE

	syscall

	jc _err				; break if error

	pop rdi				; saved fd -> rdi (for next read call)
	jmp _read

_err:					; set up err msg display
	lea rsi, [rel errmsg]
	mov rdi, STDERR
	mov rdx, ERRMSG_LEN
	mov rax, SYSCALL_WRITE
	syscall
	mov rax, ERR

_done:
	pop rdi				; pop fd a final time
	leave
	ret
