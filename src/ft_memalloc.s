section .text
    global _ft_memalloc
    extern _ft_bzero
    extern _malloc

_ft_memalloc:       ; void	*ft_memalloc(size_t size)
    push rbp
    mov rbp, rsp

    mov rax, 0      ; zero out rax, because you have to sometimes
    mov rsi, 0      ; zero out rsi, because same

    mov r10, rdi    ; save size

    call _malloc    ; TODO: ret null if fail

    cmp rax, 0      ; check if malloc fail
    je _done

    cmp r10, 0      ; check if size is 0
    je _done

    mov rdi, rax    ; save malloc result to pass to bzero
    
    mov rsi, r10         ; size as second arg for bzero
    call _ft_bzero

_done:
    mov rsp, rbp    ; epilogue, stack pointer now where it was
    pop rbp         ; are these backwards?
    ret

