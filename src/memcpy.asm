BITS 64

section .text
global memcpy

memcpy:
    xor rax, rax
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue

    lea rax, [rdi]
    ret

    .continue:
    mov al, [rsi*1+rcx]
    mov byte [rdi*1+rcx], al
    inc rcx
    jmp .while
