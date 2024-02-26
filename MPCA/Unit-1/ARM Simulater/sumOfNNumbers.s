@ Program to find the sum of N NUMBERS ( use conditional branch ). 
@ Store the result in memory location.

.data
    a: .word 10,20,30,40,50
    SUM: .word 0
.text
    LDR R0, =a
    LDR R1, =a
    LDR R2, =SUM
    MOV R4, #0
    MOV R5, #0
    L1:
        LDR R3, [R1]
        ADD R4, R4, R3
        ADD R1, R1, #4
        ADD R5, R5, #1
        CMP R5, #5
        BNE L1
        STR R4, [R2]
        SWI 0X11