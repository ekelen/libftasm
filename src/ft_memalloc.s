section .text
    global _ft_memalloc
    extern _ft_bzero
    extern _malloc

_ft_memalloc:           ; void	*ft_memalloc(size_t size)
    push rbp
    mov rbp, rsp

    push rdi            ; save size

    call _malloc

    mov r12, rax        ; save addr to r12
    pop r10             ; pop size into r10

    cmp rax, 0          ; check if malloc fail
    je _done

    cmp r10, 0          ; check if size is 0 (nothing to clear)
    je _done

    jmp _clear_memory

_clear_memory:
    mov rdi, rax        ; save malloc result to pass to bzero
    
    mov rsi, r10        ; size as second arg for bzero
    call _ft_bzero

    jmp _done

_done:
    mov rsp, rbp
    pop rbp
    ret
