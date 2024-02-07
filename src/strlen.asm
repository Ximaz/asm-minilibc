BITS 64
section .text
%if CRITERION
global _strlen
_strlen:
%else
global strlen
strlen:
%endif
    xor rax, rax

    .while:
    cmp byte [rdi+rax], 0
    jnz .continue

    ret

    .continue:
    inc rax
    jmp .while
