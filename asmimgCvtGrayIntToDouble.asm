
section .data
zero dq 0.0
var1 dq 255.0
section .text
default rel
bits 64
global asmimgCvtGrayIntToDouble

asmimgCvtGrayIntToDouble:
    ;write your code here
    
    ; rcx <- total
    ; rdx <- *matrix
    ; r8 <- *f_matrix
    movsd xmm0, [var1]
    movsd xmm1, [zero]
    
L1:    
    XOR RBX, RBX
    mov BL, [RDX]
    
    CVTSI2SD xmm1, RBX
    DIVSD xmm1, xmm0
    
    movsd qword[r8], xmm1
    
    add RDX, 1
    add R8, 8

    
    loop L1
    
    
    
    
    
    
    xor rax, rax
    ret