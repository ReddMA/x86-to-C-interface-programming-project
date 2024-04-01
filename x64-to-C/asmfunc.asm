section .text
global dot_product_asm
bits 64

dot_product_asm:
    ; rcx = pointer to first vector
    ; rdx = pointer to second vector
    ; r8 = length of vectors
    xor rsi, rsi              ; Index i = 0
    xorpd xmm0, xmm0          ; xmm0 = 0 (accumulator for the dot product result)

loop_start:
    cmp rsi, r8               ; Compare i with n
    jge loop_end              ; If i >= n, exit loop

    ; Multiply vectors element-wise and accumulate
    movsd xmm1, [rcx + rsi*8] ; Load element of first vector into xmm1
    movsd xmm2, [rdx + rsi*8] ; Load element of second vector into xmm2
    mulsd xmm1, xmm2          ; xmm1 = xmm1 * xmm2 (element-wise multiplication)
    addsd xmm0, xmm1          ; Accumulate the result: xmm0 += xmm1

    inc rsi                   ; Increment index i
    jmp loop_start            ; Jump back to the start of the loop

loop_end:
    movsd xmm1, xmm0          ; Move the result into xmm1 for return
    ret
