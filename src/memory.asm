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

    cmp rsi, rdi
    jl .overlapping

    rep movsb
    ret

    .overlapping:
    dec rdx
    add rsi, rdx
    add rdi, rdx
    std
    rep movsb
    cld
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