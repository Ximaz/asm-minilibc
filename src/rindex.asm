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
global _rindex
_rindex:
%else
global rindex
rindex:
%endif
    call .Lstrlen

    .while:
    cmp rax, 0
    je .return

    dec rax

    cmp byte [rdi+rax], sil
    jne .while

    .return:
    lea rax, [rdi+rax]
    ret
