BITS 64
section .text

%if CRITERION
global _strcmp
_strcmp:
%else
global strcmp
strcmp:
%endif
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
