BITS 64

section .text

.Lstrlen:
    xor rax, rax

    .strlen_while:
    cmp byte [rdi+rax], 0
    jne .strlen_continue

    ret

    .strlen_continue:
    inc rax
    jmp .strlen_while

%if CRITERION
global _strpbrk
_strpbrk:
%else
global strpbrk
strpbrk:
%endif
    xor rcx, rcx

    call .Lstrlen
    cmp rax, 0
    je .fast_end
    mov rdx, rax

    push rdi
    mov rdi, rsi
    call .Lstrlen
    pop rdi
    cmp rax, 0
    je .fast_end
    mov r9, rax
    xor rax, rax

    jmp .for_rcx_in_range_len_rdi
    .increment_rcx:
    inc rcx
    .for_rcx_in_range_len_rdi:
    xor r8, r8
    .for_r8_in_range_len_rsi:
    cmp r8, r9
    je .for_rcx_in_range_len_rdi
    mov al, byte [rdi + rcx]
    cmp al, byte [rsi + r8]
    je .end
    inc r8
    jmp .increment_rcx

    .end:
    cmp rcx, rdx
    jge .fast_end
    lea rax, [rdi+rcx]
    ret

    .fast_end:
    xor rax, rax
    ret
