BITS 64
section .text

%if CRITERION
global _memset
_memset:
%else
global memset
memset:
%endif
    mov rax, rdi
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue
    ret

    .continue:
    mov [rdi+rcx], rsi
    inc rcx
    jmp .while
