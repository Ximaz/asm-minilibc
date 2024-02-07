BITS 64
section .text
global strstr
global _strstr
strlen:
    xor rax, rax

    .while:
    cmp byte [rdi*1+rax], 0
    jnz .continue

    ret

    .continue:
    inc rax
    jmp .while

strncmp:
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx

    cmp rdx, 0
    je .while
    dec rdx

    .while:
    mov bl, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp rax, rdx
    je .end

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
strstr:
_strstr:
    push rdi
    mov rdi, rsi
    call strlen
    mov rdx, rax
    pop rdi

    push rdi
    .while:
    cmp byte [rdi], 0
    je .end
    call strncmp
    cmp rax, 0
    je .end
    inc rdi
    jmp .while

    .end:
    lea rax, [rdi]
    pop rdi
    ret
