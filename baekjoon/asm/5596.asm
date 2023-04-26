extern scanf
extern printf

section .data
input: db "%d %d %d %d",0
output: db "%d",10,0
S: dd 0
T: dd 0

section .bss
minguk resd 4
manse  resd 4

section .text
    global main
main:
    push rbp
    
    mov rdi, input
    lea rsi, [minguk]
    lea rdx, [minguk+4]
    lea rcx, [minguk+8]
    lea r8,  [minguk+12]
    mov rax, 0
    call scanf

    mov rax, [S]
    mov rbx, [minguk]
    add rax, rbx
    mov rbx, [minguk+4]
    add rax, rbx
    mov rbx, [minguk+8]
    add rax, rbx
    mov rbx, [minguk+12]
    add rax, rbx
    mov [S], rax

    mov rdi, input
    lea rsi, [manse]
    lea rdx, [manse+4]
    lea rcx, [manse+8]
    lea r8,  [manse+12]
    mov rax, 0
    call scanf

    mov [T], DWORD 0

    mov rax, [T]
    mov rbx, [manse]
    add rax, rbx
    mov rbx, [manse+4]
    add rax, rbx
    mov rbx, [manse+8]
    add rax, rbx
    mov rbx, [manse+12]
    add rax, rbx
    mov [T], rax

    mov eax, [S]
    mov ebx, [T]
    cmp eax, ebx
    jl L1
    mov rax, [S]
    jmp end

L1:
    mov rax, [T]

end:
    mov rdi, output
    mov rsi, rax
    mov rax, 0
    call printf

    pop rbp
    mov rax, 0
    ret