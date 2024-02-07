BITS 64

section .text

global strcspn
global _strcspn
strlen:
    xor rax, rax

    .while:
    cmp byte [rdi*1+rax], 0
    jnz .continue

    ret

    .continue:
    inc rax
    jmp .while

strcspn:
_strcspn:
    xor r8, r8

    call strlen
    mov r10, rax
    push rdi
    mov rdi, rsi
    call strlen
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
