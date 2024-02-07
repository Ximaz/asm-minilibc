BITS 64
section .text
global rindex
global _rindex
strlen:
    xor rax, rax

    .while:
    cmp byte [rdi*1+rax], 0
    jnz .continue

    ret

    .continue:
    inc rax
    jmp .while
rindex:
_rindex:
    call strlen

    .while:
    cmp rax, 0
    je .return

    dec rax

    cmp byte [rdi*1+rax], sil
    jne .while

    .return:
    lea rax, [rdi*1+rax]
    ret
