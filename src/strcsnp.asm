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
    xor r8, r8

    call .Lstrlen
    mov r10, rax
    push rdi
    mov rdi, rsi
    call .Lstrlen
    mov r11, rax
    pop rdi
    xor rax, rax

    jmp .for_r8_in_range_len_rdi
    .increment_r8:
    inc r8
    .for_r8_in_range_len_rdi:
    xor r9, r9
    .for_r9_in_range_len_rsi:
    cmp r9, r11
    je .for_r8_in_range_len_rdi
    mov al, byte [rdi + r8]
    cmp al, byte [rsi + r9]
    je .end
    inc r9
    jmp .increment_r8

    .end:
    mov rax, r8
    ret
