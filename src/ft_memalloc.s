section .data
    no_size: db 'No size', 0x0a, 0x0
    malloc_fail: db 'Malloc fail', 0x0a, 0x0

section .text
    extern _puts
    global _ft_memalloc
    extern _ft_bzero
    extern _malloc

_ft_memalloc:       ; void	*ft_memalloc(size_t size)
    push rbp
    mov rbp, rsp

    mov rax, 0      ; zero out rax, because you have to sometimes
    mov rsi, 0      ; zero out rsi, because same

    ; mov r10, rdi    ; save size ; j/k that's not callee-saved

    push rdi        ; save size

    call _malloc

    mov r12, rax    ; save addr to r12
    pop r10         ; pop size into r10

    cmp rax, 0          ; check if malloc fail
    je _done

    cmp r10, 0          ; check if size is 0 (nothing to clear)
    je _done

    ; --------------


    ; mov rdi, rax      ; save malloc result to pass to bzero
    ; mov r11, rax      ; for security purposes
    
    ; mov rsi, r10         ; size as second arg for bzero
    ; call _ft_bzero

    ; mov rax, r11
    jmp _done

_done:
    mov rsp, rbp
    pop rbp
    ret

