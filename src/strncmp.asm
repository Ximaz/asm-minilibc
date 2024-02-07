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
    xor r8, r8
    xor rcx, rcx

    cmp rdx, 0
    je .while
    dec rdx

    .while:
    mov r8b, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp rax, rdx
    je .end

    cmp r8b, 0
    je .end

    cmp cl, 0
    je .end

    cmp r8b, cl
    jne .end

    inc rax
    jmp .while

    .end:
    xor rax, rax
    mov rax, r8
    sub rax, rcx
    ret
