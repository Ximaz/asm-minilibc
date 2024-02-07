BITS 64
section .text

%if CRITERION
global _memset
_memset:
%else
global memset
memset:
%endif
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue

    mov rax, rdi
    ret

    .continue:
    mov [rdi+rcx], rsi
    inc rcx
    jmp .while
