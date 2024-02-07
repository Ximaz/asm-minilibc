BITS 64
section .text
global strchr

strlen:
    xor rax, rax

    .while:
    cmp byte [rdi*1+rax], 0
    jnz .continue

    ret

    .continue:
    inc rax
    jmp .while

strrchr:
    call strlen
    dec rax

    .while:
    cmp byte [rdi*1+rax], 0
    jz .return

    cmp byte [rdi*1+rax], sil
    jnz .continue

    .return:
    lea rax, [rdi*1+rax]
    ret

    .continue:
    dec rax
    jmp .while
