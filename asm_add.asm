SECTION .data
    extern printf
    global main

fmt:
    db "%d", 10, 0

SECTION .text

main:
    mov     eax, 21
    mov     ebx, 69
    add     eax, ebx

    push    eax
    push    fmt
    call    printf
    add     esp, 8      ; clean stack

    mov     eax, 0      ; return 0
    ret