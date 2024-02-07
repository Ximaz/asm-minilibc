BITS 64
section .text
global _strcmp

strcmp:
_strcmp:
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx

    .while:
    mov bl, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp bl, 0
    je .end

    cmp cl, 0
    je .end

    cmp bl, cl
    jne .end

    inc rax
    jmp .while

    .end:
    xor rax, rax
    mov rax, rbx
    sub rax, rcx
    ret
