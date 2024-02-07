BITS 64

section .text

global strcasecmp
global _strcasecmp

strcasecmp:
_strcasecmp:
    xor rbx, rbx
    xor rax, rax
    xor rcx, rcx

    .while:
    mov al, byte[rdi + rbx]
    mov cl, byte[rsi + rbx]
    inc rbx

    cmp al, 0
    je .end

    cmp cl, 0
    je .end
    
    xor al, 0b1111111
    and al, cl
    shl ax, 2
    test al, 0b1111100
    jz .while

    .end:
    dec rbx
    mov al, byte [rdi + rbx]
    xor rbx, rbx
    mov rbx, rbx
    sub rbx, rcx
    mov rax, rbx
    ret
