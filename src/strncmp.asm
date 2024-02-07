BITS 64
section .text

%if CRITERION
global _strncmp
_strncmp:
%else
global strncmp
strncmp:
%endif
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
