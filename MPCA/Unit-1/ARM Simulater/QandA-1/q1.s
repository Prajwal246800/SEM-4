@ Compile the following  C assignment statements into ARM.
    @ A = B + C;
    @ D = A – C;
    @ Perform D = A - C using RSB instruction.

@ Note: User different addressing modes both at source & destination operand positions.

MOV R1, #2       @ B = 2
MOV R2, #4       @ C = 4
ADD R0, R1, R2   @ A = B + C; A = 2 + 4; A = 6;
RSB R3, R2, R0   @ D = A - C; D = 6 - 4; D = 2;