BITS 64

section .text

%if CRITERION
global _strcasecmp
_strcasecmp:
%else
global strcasecmp
strcasecmp:
%endif
    xor rcx, rcx
    xor r8, r8
    xor r9, r9

    .while:
    mov r8b, byte[rdi + rcx]
    mov r9b, byte[rsi + rcx]
    inc rcx

    cmp r8b, 0
    je .end

    cmp r9b, 0
    je .end
    
    xor r8b, r9b
    cmp r8b, 32
    jne .end
    jmp .while

    .end:
    xor rax, rax
    dec rcx
    mov r8b, byte [rdi + rcx]
    mov rax, r8
    sub rax, r9
    ret
