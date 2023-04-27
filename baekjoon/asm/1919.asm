extern scanf
extern printf

section .data
input: db "%s",0
output: db "%d",10,0

section .bss
buffer: resb 1024
alphabet: resd 26
i: resd 1
cnt: resd 1

section .text
    global main
main:
    push rbp

    mov edi, input
    lea esi, [buffer]
    mov eax, 0
    call scanf

    jmp first_str

first_str:
    mov edx, DWORD[i]
    cmp BYTE[buffer+edx], 0
    jz first_str_end

    mov al, [buffer+edx]
    movzx eax, al
    sub eax, 97

    inc DWORD[alphabet+eax*4]

    inc DWORD[i]
    jmp first_str

first_str_end:
    mov edi, input
    lea esi, [buffer]
    mov eax, 0
    call scanf

    mov [i], DWORD 0
    jmp second_str

second_str:
    mov edx, DWORD[i]
    cmp BYTE[buffer+edx], 0
    jz second_str_end

    mov al, [buffer+edx]
    movzx eax, al
    sub eax, 97

    dec DWORD[alphabet+eax*4]

    inc DWORD[i]
    jmp second_str

second_str_end:
    mov [i], DWORD 0
    jmp sum

sum:
    mov edx, DWORD[i]
    cmp edx, 26
    je end

    mov eax, [cnt]
    cmp [alphabet+edx*4], DWORD 0
    jge if
    jl else

if:
    add eax, [alphabet+edx*4]
    jmp if_end
else:
    sub eax, [alphabet+edx*4]
    jmp if_end
if_end:
    mov [cnt], eax
    
    inc DWORD[i]
    jmp sum

end:
    mov edi, output
    mov esi, [cnt]
    mov eax, 0
    call printf

    pop rbp
    mov rax, 0
    ret