BITS 64

section .text

%if CRITERION
global _ffs
_ffs:
%else
global ffs
ffs:
%endif
    mov rcx, rdi
    xor rax, rax

    .while:
    cmp rcx, 0
    je .break
    inc rax
    or rcx, 1
    cmp rcx, 1
    je .break
    shr rcx, 1
    jmp .while

    .break:
    ret
