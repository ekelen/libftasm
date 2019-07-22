section .text
    global _ft_memalloc
    extern _ft_bzero
    extern _malloc

_ft_memalloc:
    push rbp
    mov rbp, rsp

    mov rax, 0      ; zero out rax, because you have to sometimes
    mov rsi, 0      ; zero out rsi, because same

    push rdi        ; save size_t size

    call _malloc    ; TODO: ret null if fail

    mov rdi, rax    ; save malloc result to pass to bzero
    
    pop rsi         ; pop size, come on now
    call _ft_bzero

    mov rsp, rbp    ; epilogue, stack pointer now where it was
    pop rbp         ; are these backwards?
    ret

