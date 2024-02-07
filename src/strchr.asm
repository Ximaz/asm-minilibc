BITS 64
section .text
global strchr

strchr:
    xor rax, rax

    .while:
    cmp byte [rdi*1+rax], 0
    je .null_ret

    cmp byte [rdi*1+rax], sil
    jne .continue

    lea rax, [rdi*1+rax]
    ret

    .null_ret:
    xor rax, rax
    ret

    .continue:
    inc rax
    jmp .while
