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

%if CRITERION
global _strcspn
_strcspn:
%else
global strcspn
strcspn:
%endif
    xor rax, rax
    xor rcx, rcx ; len of rdi
    xor r8, r8   ; len of rsi

    .while:
    cmp byte [rdi + rcx], 0
    je .no_match_end
    xor r8, r8
    mov al, byte [rdi + rcx]
    inc rcx

    .check_all_rsi:
    cmp byte [rsi + r8], 0
    je .while
    cmp byte [rsi + r8], al
    je .end
    inc r8
    jmp .check_all_rsi

    .end:
    mov rax, r8
    ret

    .no_match_end:
    mov rax, rcx
    ret
