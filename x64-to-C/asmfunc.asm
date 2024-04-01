%include "io64.inc"

section .data
vectorA dq 1.0, 2.0, 3.0, 4.0, 5.0 ; Example vector A of length 4
vectorB dq 5.0, 4.0, 3.0, 2.0, 1.0  ; Example vector B of length 4
simd dq 0.0                    ; To store the result
n dd 5                        ; Length of each vector

section .text
global main
main:
    mov rbp, rsp               ; For correct debugging  
    mov ecx, [n]               ; Move n into ecx, the loop counter
    xor esi, esi               ; Start index at 0

loop_start:
    cmp esi, ecx               ; Compare current index with n
    jge loop_end               ; If esi >= n, we're done

    ; Load one element from vectorA into xmm0
    movsd xmm0, [vectorA + esi*8]
    ; Load one element from vectorB into xmm1
    movsd xmm1, [vectorB + esi*8]

    ; Multiply and accumulate
    mulsd xmm0, xmm1           ; xmm0 = xmm0 * xmm1
    addsd xmm2, xmm0           ; xmm2 = xmm2 + xmm0

    inc esi                    ; Move to the next element
    jmp loop_start             ; Continue loop

loop_end:
    ; Store the result
    movsd [simd], xmm2         ; Store the dot product result
    xor rax, rax
    ret
