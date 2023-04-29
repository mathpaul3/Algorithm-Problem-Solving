extern scanf
extern printf

section .data
input: db "%d %d",0
output: db "%d ",0
LF: db 10,0

section .bss
N: resd 1
M: resd 1
i: resd 1
j: resd 1
arr: resd 128

section .text
    global main
main:
    push rbp

    mov edi, input
    lea esi, [N]
    lea edx, [M]
    mov eax, 0
    call scanf

    mov [i], DWORD 1

    jmp init_arr

init_arr:
    mov edx, [i]
    cmp edx, [N]
    jg while

    mov [arr+edx*4], edx
    inc DWORD[i]
    jmp init_arr

while:
    mov r8d, DWORD[M]
    cmp r8d, DWORD 0
    je while_end

    mov edi, input
    lea esi, [i]
    lea edx, [j]
    mov eax, 0
    call scanf

    mov eax, [i]
    mov ecx, [arr+eax*4]
    mov ebx, [j]
    mov edx, [arr+ebx*4]
    xor ecx, edx
    xor edx, ecx
    xor ecx, edx
    mov [arr+eax*4], ecx
    mov [arr+ebx*4], edx

    dec DWORD[M]
    jmp while

while_end:
    mov [i], DWORD 1
    jmp print_arr

print_arr:
    mov edx, [i]
    cmp edx, [N]
    jg end

    mov edi, output
    mov esi, [arr+edx*4]
    mov eax, 0
    call printf

    inc DWORD[i]
    jmp print_arr

end:
    mov edi, LF
    mov eax, 0
    call printf

    pop rbp
    mov rax, 0
    ret