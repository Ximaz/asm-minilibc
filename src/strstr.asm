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
    xor r8, r8
    xor rcx, rcx

    cmp rdx, 0
    je .strncmp_while
    dec rdx

    .strncmp_while:
    mov r8b, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp rax, rdx
    je .strncmp_end

    cmp r8b, 0
    je .strncmp_end

    cmp cl, 0
    je .strncmp_end

    cmp r8b, cl
    jne .strncmp_end

    inc rax
    jmp .strncmp_while

    .strncmp_end:
    xor rax, rax
    mov rax, r8
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

    xor rcx, rcx

    .while:
    cmp byte [rdi + rcx], 0
    je .null_ret
    push rcx
    call .Lstrncmp
    pop rcx
    cmp rax, 0
    je .end
    inc rcx
    jmp .while

    .null_ret:
    xor rax, rax
    ret

    .end:
    lea rax, [rdi + rcx]
    ret
