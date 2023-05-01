extern scanf
extern printf

section .data
input: db "%s",0
output: db "%c",0
LF: db 10
sorry_hansoo: db "I'm Sorry Hansoo",0

section .bss
buffer: resb 128
alphabet: resd 26
i: resd 1
odd: resd 1
len: resd 1
cnt: resd 1
tmp: resd 1

section .text
    global main
main:
    push rbp

    mov edi, input
    lea esi, [buffer]
    mov eax, 0
    call scanf

    jmp cnt_str

cnt_str:
    mov edx, DWORD[i]
    cmp BYTE[buffer+edx], 0
    jz cnt_str_end

    mov al, [buffer+edx]
    movzx eax, al
    sub eax, 65

    inc DWORD[alphabet+eax*4]
    inc DWORD[i]
    inc DWORD[len]
    jmp cnt_str

cnt_str_end:
    mov [i], DWORD 0
    mov [odd], DWORD -1
    jmp find_odd

find_odd:
    mov edx, DWORD[i]
    cmp edx, DWORD 26
    je print_palindrome_inc

    mov ecx, [alphabet+edx*4]
    and ecx, 1
    jnz check_psbl
    jz find_odd_continue

check_psbl:
    mov ecx, [odd]
    cmp ecx, -1
    jne print_sorry_hansoo

    mov [odd], edx
    jmp find_odd_continue

print_sorry_hansoo:
    mov edi, sorry_hansoo
    mov eax, 0
    call printf
    jmp end

find_odd_continue:
    inc DWORD[i]
    jmp find_odd

print_palindrome_inc:
    mov [i], DWORD 0
    jmp for_alpha_inc

for_alpha_inc:
    mov edx, DWORD[i]
    cmp edx, DWORD 26
    je print_palindrome_dec

    mov ecx, [alphabet+edx*4]
    shr ecx, 1
    mov [tmp], ecx

    jmp print_while_inc

print_while_inc:
    mov ecx, [tmp]
    cmp ecx, DWORD 0
    jz for_alpha_inc_continue

    mov edx, DWORD[i]
    add edx, DWORD 65

    mov edi, output
    mov esi, edx
    mov eax, 0
    call printf

    dec DWORD[tmp]
    jmp print_while_inc

for_alpha_inc_continue:
    inc DWORD[i]
    jmp for_alpha_inc

print_palindrome_dec:
    mov eax, [odd]
    cmp eax, -1
    jne print_odd
    jmp print_palindrome_dec_continue

print_odd:
    mov eax, [odd]
    add eax, 65

    mov edi, output
    mov esi, eax
    mov eax, 0
    call printf

    jmp print_palindrome_dec_continue

print_palindrome_dec_continue:
    dec DWORD[i]
    jmp for_alpha_dec

for_alpha_dec:
    mov edx, DWORD[i]
    cmp edx, DWORD 0
    jl end

    mov ecx, [alphabet+edx*4]
    shr ecx, 1
    mov [tmp], ecx

    jmp print_while_dec

print_while_dec:
    mov ecx, [tmp]
    cmp ecx, 0
    je for_alpha_dec_continue

    mov edx, DWORD[i]
    add edx, 65
    mov edi, output
    mov esi, edx
    mov eax, 0
    call printf

    dec DWORD[tmp]
    jmp print_while_dec

for_alpha_dec_continue:
    dec DWORD[i]
    jmp for_alpha_dec

end:
    mov edi, output
    mov esi, [LF]
    mov eax, 0
    call printf

    pop rbp
    mov rax, 0
    ret