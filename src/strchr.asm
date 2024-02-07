BITS 64
section .text

%if CRITERION
global _strchr
_strchr:
%else
global strchr
strchr:
%endif
    xor rax, rax

    .while:
    cmp byte [rdi+rax], 0
    je .null_ret

    cmp byte [rdi+rax], sil
    jne .continue

    lea rax, [rdi+rax]
    ret

    .null_ret:
    xor rax, rax
    ret

    .continue:
    inc rax
    jmp .while
