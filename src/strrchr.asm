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
global _strrchr
_strrchr:
%else
global strrchr
strrchr:
%endif
    call .Lstrlen

    .while:
    cmp rax, 0
    jl .null_ret

    cmp byte [rdi+rax], sil
    jne .continue

    lea rax, [rdi+rax]
    ret

    .null_ret:
    xor rax, rax
    ret

    .continue:
    dec rax
    jmp .while
