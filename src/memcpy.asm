BITS 64

section .text

%if CRITERION
global _memcpy
_memcpy:
%else
global memcpy
memcpy:
%endif
    mov rax, rdi

    xor rax, rax
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue
    ret

    .continue:
    mov al, [rsi*1+rcx]
    mov byte [rdi+rcx], al
    inc rcx
    jmp .while
