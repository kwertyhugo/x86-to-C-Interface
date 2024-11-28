section .text
bits 64
default rel
global asmfunc

asmfunc:
    ; rcx = n
    ; rdx = x1
    ; r8  = x2
    ; r9  = y1
    ; rbp + 32 = y2
    ; rbp + 40 = zAsm
    push rbp
    mov rbp, rsp
    add rbp, 16

    mov r10, [rbp + 32]
    mov r11, [rbp + 40]

loop:
    dec rcx 

    movss xmm0, [rdx + 4*rcx]
    movss xmm1, [r8 + 4*rcx]
    movss xmm2, [r9 + 4*rcx]
    movss xmm3, [r10 + 4*rcx]

    
    subss xmm0, xmm1  ; xmm0 = x1 - x2
    subss xmm2, xmm3  ; xmm2 = y1 - y2

    mulss xmm0, xmm0  ; xmm0 = (x1 - x2)^2
    mulss xmm2, xmm2  ; xmm2 = (y1 - y2)^2

    addss xmm0, xmm2  ; xmm0 = (x1 - x2)^2 + (y1 - y2)^2

    sqrtss xmm0, xmm0 ; xmm0 = sqrt((x1 - x2)^2 + (y1 - y2)^2)

    
    movss [r11 + 4*rcx], xmm0

    cmp rcx, 0        ; Compare rcx with 0
    jg loop           ; If rcx > 0, jump back to the loop

    pop rbp
    ret               ; Return from function
