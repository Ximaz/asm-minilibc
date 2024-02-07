BITS 64
section .text
.Lstrlen:
    xor rax, rax

    .strlen_while:
    cmp byte [rdi+rax], 0
    jnz .strlen_continue

    ret

    .strlen_continue:
    inc rax
    jmp .strlen_while

.Lstrncmp:
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx

    cmp rdx, 0
    je .strncmp_while
    dec rdx

    .strncmp_while:
    mov bl, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp rax, rdx
    je .strncmp_end

    cmp bl, 0
    je .strncmp_end

    cmp cl, 0
    je .strncmp_end

    cmp bl, cl
    jne .strncmp_end

    inc rax
    jmp .strncmp_while

    .strncmp_end:
    xor rax, rax
    mov rax, rbx
    sub rax, rcx
    ret

%if CRITERION
global _strstr
_strstr:
%else
global strstr
strstr:
%endif
    push rdi
    mov rdi, rsi
    call .Lstrlen
    mov rdx, rax
    pop rdi

    push rdi
    .while:
    cmp dil, 0
    je .end
    call .Lstrncmp
    cmp rax, 0
    je .end
    inc rdi
    jmp .while

    .end:
    mov rax, rdi
    pop rdi
    ret
