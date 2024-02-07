BITS 64
section .text
global strrchr

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
    cmp rax, 0
    je .null_ret

    cmp byte [rdi*1+rax], sil
    jne .continue

    lea rax, [rdi*1+rax]
    ret

    null_ret:
    xor rax, rax
    ret

    .continue:
    dec rax
    jmp .while
