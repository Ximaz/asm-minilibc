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

    xor rax, rax
    xor rcx, rcx

    .while:
    cmp rcx, rdx
    jnz .continue
    ret

    .continue:
    mov al, [rsi*1+rcx]
    mov byte [rdi+rcx], al
    inc rcx
    jmp .while

%if CRITERION
global _memmove
_memmove:
%else
global memmove
memmove:
%endif
    cmp rdi, 0
    je .end
    cmp rsi, 0
    je .end

    mov rax, rdi
    cmp rdi, rsi
    je .end             ;; rdi == rsi, nothing to do
    jl .no_overlapping  ;; rdi <  rsi, no overlap, we safely can copy

    mov rcx, rsi        ;; rcx = rsi
    add rcx, rdx        ;; rcx = rcx + rdx
    cmp rdi, rcx
    jge .no_overlapping ;; rdi >= rsi + rdx, no overlap, we safely can copy

    .overlapping:
    ;; when overlapping, we want to copy frmo right to left instead of left to
    ;; right, so we make sure we're not overwriting existing data before it's
    ;; copied into the destination buffer.
    std              ;; sets the direction flag to 1 (right-to-left)
    mov rcx, rdx     ;; sets the number of reps for movsb

    dec rdx          ;; rdx = rdx - 1
    add rsi, rdx     ;; rsi = &rsi[rdx]
    add rdi, rdx     ;; rdi = &rdi[rdx]
    rep movsb        ;; movsb sets DS:SI and ES:DI by itself to copy rcx times

    cld              ;; unsets the direction flag, i's now 0 (left-to-right)
    ret

    .no_overlapping:
    mov rcx, rdx     ;; sets the number of reps for movsb
    rep movsb        ;; movsb sets DS:SI and ES:DI by itself to copy rcx times

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