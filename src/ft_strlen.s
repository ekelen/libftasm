section .text
	global _ft_strlen

_ft_strlen:				; size_t ft_strlen(const char *s)
	enter 0x10, 0

	mov rcx, 0
	not rcx					; initialize counter to max uint64
	mov al, 0

_get_char:

	cld							; work left-to-right

	repnz scasb			; repnz:
									;		for maximum rcx iterations,
									; 	repeat while zero flag not set
									; scasb:
									;		what is al - byte[rdi]?
									;		(what is 0 - rdi?)
									;		if 0, set ZF
									;		increment di by 1

_done:
	not rcx
	sub rcx, 1		; invert rcx to get strlen
	mov rax, rcx
	leave

_return:
	ret