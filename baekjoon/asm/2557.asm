section .data
    msg db "Hello World!", 0x0A

section .text
    global main

main:
    mov eax, 1
    mov rdi, 1
    mov rsi, msg
    mov edx, 13
    syscall