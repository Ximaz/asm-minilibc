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
    xchg rdi, rsi
    call .Lstrlen
    mov rdx, rax
    xchg rdi, rsi

    cmp rax, 0
    je .found

    .while:
    cmp byte [rdi], 0
    je .check_for_empty_needle
    call .Lstrncmp
    cmp rax, 0
    je .found
    inc rdi
    jmp .while

    .check_for_empty_needle:
    cmp byte [rsi], 0
    je .found
    jmp .not_found

    .found:
    cmp rax, 0
    jne .not_found
    mov rax, rdi
    ret

    .not_found:
    xor rax, rax
    ret
