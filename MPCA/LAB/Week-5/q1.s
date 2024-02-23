@ Write an ALP using conditional ARM instructions to sort an array of numbers using Bubble sort Algorithm
.data
    a: .word 12,10,3,8,7,4,1
.text
    MOV R3, #6
LOOP1:
    LDR R1, =a
    MOV R2, R1
    MOV R7, R3
LOOP2:
    LDR R4, [R1]
    ADD R6, R1, #4
    LDR R5, [R6]
    CMP R4, R5
    BMI SKIP
    STR R4, [R6]
    STR R5, [R1]
SKIP:
    SUBS R7, R7, #1
    ADD R1, R1, #4
    BNE LOOP2
    SUBS R3, R3, #1
    BNE LOOP1