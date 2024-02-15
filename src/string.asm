BITS 64
section .text

%if CRITERION
global _strlen
_strlen:
%else
global strlen
strlen:
%endif
    xor rax, rax

    .while:
    cmp byte [rdi+rax], 0
    jnz .continue

    ret

    .continue:
    inc rax
    jmp .while

%if CRITERION
global _strchr
global _index
_strchr:
_index:
%else
global strchr
global index
strchr:
index:
%endif
    xor rax, rax

    .while:
    cmp byte [rdi+rax], 0
    je .null_ret

    cmp byte [rdi+rax], sil
    jne .continue

    .ret:
    lea rax, [rdi+rax]
    ret

    .null_ret:
    cmp sil, 0
    je .ret
    xor rax, rax
    ret

    .continue:
    inc rax
    jmp .while

%if CRITERION
global _strrchr
global _rindex
_strrchr:
_rindex:
%else
global strrchr
global rindex
strrchr:
rindex:
%endif
%if CRITERION
    call _strlen
%else
    call strlen
%endif
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

%if CRITERION
global _strcmp
_strcmp:
%else
global strcmp
strcmp:
%endif
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx

    .while:
    mov bl, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp bl, 0
    je .end

    cmp cl, 0
    je .end

    cmp bl, cl
    jne .end

    inc rax
    jmp .while

    .end:
    xor rax, rax
    mov rax, rbx
    sub rax, rcx
    ret

%if CRITERION
global _strncmp
_strncmp:
%else
global strncmp
strncmp:
%endif
    xor rax, rax
    xor r8, r8
    xor rcx, rcx

    cmp rdx, 0
    je .while
    dec rdx

    .while:
    mov r8b, byte[rdi + rax]
    mov cl, byte[rsi + rax]

    cmp rax, rdx
    je .end

    cmp r8b, 0
    je .end

    cmp cl, 0
    je .end

    cmp r8b, cl
    jne .end

    inc rax
    jmp .while

    .end:
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
    xor rcx, rcx
    mov rax, rdi
    cmp byte [rsi], 0
    je .fast_return

    cmp byte [rdi], 0
    je .null_ret

    xor r8, r8

    .strstr:
    cmp byte[rdi + rcx], 0
    je .return
    mov rdx, 1

    .while:
    mov r8, rcx
    add r8, rdx
    movzx rax, byte[rdi + r8]
    cmp byte [rsi + rdx], 0
    je .return
    cmp byte [rsi + rdx], al
    je .continue
    inc rcx
    jmp .strstr

    .continue:
    inc rdx
    jmp .while

    .null_ret:
    xor rax, rax
    ret

    .return:
    cmp byte [rsi + rdx], 0
    jne .null_ret

    .fast_return:
    lea rax, [rdi + rcx]
    ret

%if CRITERION
global _strcspn
_strcspn:
%else
global strcspn
strcspn:
%endif
    xor rax, rax
    xor rcx, rcx
    xor r8, r8  

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

%if CRITERION
global _strpbrk
_strpbrk:
%else
global strpbrk
strpbrk:
%endif
    xor rcx, rcx
    xor rax, rax
    mov rdx, rsi

    .while:
    movzx rsi, byte [rdx + rcx]
    cmp rsi, 0
    je .null_ret
%if CRITERION
    call _strchr
%else
    call strchr
%endif
    cmp rax, 0
    jne .return
    inc rcx
    jmp .while

    .null_ret:
    xor rax, rax
    .return:
    ret

%if CRITERION
global _strcasecmp
_strcasecmp:
%else
global strcasecmp
strcasecmp:
%endif
    xor rax, rax
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
    
    cmp r8b, r9b
    je .while

    xor r8b, r9b
    cmp r8b, 32
    je .while

    .end:
    dec rcx
    mov r8b, byte [rdi + rcx]
    movzx rax, r8b
    sub rax, r9
    ret
