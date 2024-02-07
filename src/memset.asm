BITS 64
section .text
global memset

memset:
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue

    lea rax, [rdi]
    ret

    .continue:
    mov [rdi*1+rcx], rsi
    inc rcx
    jmp .while
