extern scanf
extern printf

section .data
input: db "%d",0
output: db "%d",0
LF: db 10

section .bss
K: resd 1
i: resd 1
bit_arr: resd 32

section .text
    global main
main:
    push rbp

    mov edi, input
    lea esi, [K]
    mov eax, 0
    call scanf

    inc DWORD[K]
    jmp while

while:
    mov eax, DWORD[K]
    cmp eax, 0
    jz main_1

    mov eax, DWORD[K]
    mov ecx, DWORD[i]
    mov [bit_arr+ecx*4], eax

    inc DWORD[i]
    shr DWORD[K], 1
    jmp while

main_1:
    dec DWORD[i]
    dec DWORD[i]
    jmp print_while

print_while:
    mov ecx, DWORD[i]
    cmp ecx, DWORD 0
    jl end

    mov eax, [bit_arr+ecx*4]
    and eax, DWORD 1
    cmp eax, DWORD 1
    je seven
    jmp four

seven:
    mov edi, output
    mov esi, 7
    mov eax, 0
    call printf
    jmp print_while_1

four:
    mov edi, output
    mov esi, 4
    mov eax, 0
    call printf
    jmp print_while_1

print_while_1:
    dec DWORD[i]
    jmp print_while

end:
    mov edi, LF
    mov eax, 0
    call printf

    pop rbp
    mov eax, 0
    ret