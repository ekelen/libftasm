section .text
  global _ft_strchr
  extern _ft_strlen

_ft_strchr:           		; char *ft_strchr(const char *s, int c)

	;; TODO: PROLOGUE/EPILOGUE?

  ;; TODO: TESTS
		push		rdi       		; save s
		mov 		al, sil   		; c to rax

_search:
		cmp			byte[rdi], 0  ; s == \0 ?
		je 			_null_found
		cmp			byte[rdi], al ; s == c ?
		je			_found
		inc			rdi           ; s++
		jmp 		_search

_null_found:
		cmp			al, 0					; c == \0 ?
		je			_found
		mov			rax, 0
		pop			rdi
		jmp     _return

_found:
		mov 		rax, rdi
		pop			rdi
    jmp     _return

_return:
    ; pop rdi ; TODO: just put here
		ret