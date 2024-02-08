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
_strchr:
%else
global strchr
strchr:
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
    xchg rdi, rsi
%if CRITERION
    call _strlen
%else
    call strlen
%endif

    mov rdx, rax
    xchg rdi, rsi

    cmp rax, 0
    je .found

    .while:
    cmp byte [rdi], 0
    je .check_for_empty_needle
%if CRITERION
    call _strncmp
%else
    call strncmp
%endif
    cmp rax, 0
    je .found
    inc rdi
    jmp .while

    .check_for_empty_needle:
    cmp byte [rsi], 0
    je .found
    jmp .not_found

    .found:
    cmp rax, 0
    jne .not_found
    mov rax, rdi
    ret

    .not_found:
    xor rax, rax
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

    %if CRITERION
    call _strlen
%else
    call strlen
%endif

    cmp rax, 0
    je .fast_end
    mov rdx, rax

    push rdi
    mov rdi, rsi
    %if CRITERION
    call _strlen
%else
    call strlen
%endif

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
