BITS 64
section .text

%if CRITERION
global _memcpy
_memcpy:
%else
global memcpy
memcpy:
%endif
    mov rax, rdi
    mov rcx, rdx
    rep movsb
    ret

%if CRITERION
global _memmove
_memmove:
%else
global memmove
memmove:
%endif
    mov rax, rdi
    mov rcx, rdx

    cmp rdi, 0
    je .end

    cmp rsi, 0
    je .end

    sub rax, rcx
    cmp rsi, rax
    jle .no_overlapping

    mov rax, rdi
    add rax, rcx
    cmp rsi, rax
    jle .no_overlapping

    .overlapping:
    mov rax, rdi
    std
    dec rdx
    add rsi, rdx
    add rdi, rdx
    rep movsb

    cld
    ret

    .no_overlapping:
    mov rax, rdi
    rep movsb

    .end:
    ret

%if CRITERION
global _memset
_memset:
%else
global memset
memset:
%endif
    mov rax, rdi
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue
    ret

    .continue:
    mov [rdi+rcx], rsi
    inc rcx
    jmp .while

%if CRITERION
global _memfrob
_memfrob:
%else
global memfrob
memfrob:
%endif
    mov rax, rdi
    xor rcx, rcx

    .while:
        cmp rcx, rsi
        je .break
        xor byte [rdi + rcx], 42
        inc rcx
        jmp .while

    .break:
    ret