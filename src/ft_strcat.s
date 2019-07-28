section .text
	global _ft_strcat

_ft_strcat:								; char *strcat(char *restrict s1, const char *restrict s2);

	push rbp
	mov rbp, rsp
	sub rsp, 8

	mov rcx, 0							; zero out counters
	mov rdx, 0

_s1:
	mov al, byte[rdi + rcx]	; put current s1 char in scratch
	cmp al, 0								; char == 0 ?
	je _cat

	inc rcx
	jmp _s1

_cat:
	mov al, byte[rsi + rdx]	; put current s2 char in tmp
	cmp al, 0
	je _done
	mov byte[rdi + rcx], al
	inc rdx
	inc rcx
	jmp _cat

_done:
	mov byte[rdi + rcx], 0	; add \0
	mov rax, rdi
	leave
	ret