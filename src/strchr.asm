BITS 64
section .text
global strchr

strchr:
    xor rax, rax

    .while:
    cmp byte [rdi*1+rax], 0
    jz .return

    cmp byte [rdi*1+rax], sil
    jnz .continue

    .return:
    lea rax, [rdi*1+rax]
    ret

    .continue:
    inc rax
    jmp .while
